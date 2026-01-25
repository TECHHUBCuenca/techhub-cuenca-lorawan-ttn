#include "LoRaWan_APP.h"          // Stack LoRaWAN de Heltec
#include "HT_SSD1306Wire.h"       // Driver OLED Heltec
#include <Wire.h>

// ======================================================
// ================= DISPLAY OLED =======================
// ======================================================
// El objeto 'display' ya está instanciado dentro
// de la librería oficial de Heltec
extern SSD1306Wire display;

// ======================================================
// ================== OTAA KEYS =========================
// ======================================================
// Identificadores OTAA asignados por TTN
// (Nodo 1 – Sensor de temperatura)

uint8_t devEui[8] = {
  0x2B, 0x60, 0x79, 0xCE,
  0x32, 0x5A, 0x6D, 0x85
};

uint8_t appEui[8] = {
  0xAB, 0xCF, 0x5B, 0x76,
  0xDA, 0x19, 0x94, 0xFF
};

uint8_t appKey[16] = {
  0xE3, 0xCE, 0x19, 0x56,
  0x65, 0xBA, 0x43, 0xFB,
  0x01, 0xD8, 0x3B, 0x1A,
  0xD3, 0x35, 0x17, 0xA0
};

// ======================================================
// ===== VARIABLES REQUERIDAS POR LA LIBRERÍA ============
// ======================================================
// Aunque se use OTAA, la librería exige estas variables
// (no se usan directamente)

uint32_t devAddr = 0;
uint8_t nwkSKey[16] = {0};
uint8_t appSKey[16] = {0};

// ======================================================
// ============== PARÁMETROS LoRaWAN ====================
// ======================================================

// US915 – Sub-banda 0 (canales 0 al 7)
uint16_t userChannelsMask[6] = {
  0x00FF, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000
};

// Región y clase del dispositivo
LoRaMacRegion_t loraWanRegion = LORAMAC_REGION_US915;
DeviceClass_t loraWanClass = CLASS_A;

// Parámetros de transmisión
uint32_t appTxDutyCycle = 1000;     // 1 segundo
bool overTheAirActivation = true;   // OTAA
bool loraWanAdr = false;            // ADR deshabilitado
bool isTxConfirmed = false;         // Uplink no confirmado
uint8_t appPort = 2;                // Puerto de aplicación
uint8_t confirmedNbTrials = 8;

// ======================================================
// =============== FUNCIONES OLED =======================
// ======================================================

void showStatus(String line1, String line2) {
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Nodo 1 - LoRaWAN");
  display.drawLine(0, 12, 127, 12);
  display.drawString(0, 20, line1);
  display.drawString(0, 34, line2);
  display.display();
}

// ======================================================
// =============== PAYLOAD UPLINK =======================
// ======================================================
// Envía temperatura simulada (°C * 10)

static void prepareTxFrame(uint8_t port) {

  float temp = 20.0 + random(-50, 50) / 10.0;   // 15–25 °C
  int16_t temp_int = temp * 10;

  // Payload binario (big endian)
  appData[0] = (temp_int >> 8) & 0xFF;
  appData[1] = temp_int & 0xFF;
  appDataSize = 2;

  Serial.print("Nodo 1 TX -> Temp: ");
  Serial.print(temp);
  Serial.println(" C");

  showStatus("TX Temperatura", String(temp) + " C");
}

// ======================================================
// ======================= SETUP ========================
// ======================================================

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Encender OLED (control de energía Heltec)
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);
  delay(50);

  display.init();
  display.clear();
  display.display();

  // Inicialización MCU y radio LoRa
  Mcu.begin(HELTEC_BOARD, SLOW_CLK_TPYE);

  Serial.println("Nodo 1 iniciado - OTAA");
  showStatus("INIT", "Esperando JOIN");
}

// ======================================================
// ======================== LOOP ========================
// ======================================================

void loop() {

  switch (deviceState) {

    case DEVICE_STATE_INIT:
      LoRaWAN.init(loraWanClass, loraWanRegion);
      LoRaWAN.setDefaultDR(3);     // DR3 ≈ SF9 en US915
      deviceState = DEVICE_STATE_JOIN;
      break;

    case DEVICE_STATE_JOIN:
      Serial.println("Nodo 1 -> JOIN OTAA...");
      showStatus("JOIN", "Enviando request");
      LoRaWAN.join();
      break;

    case DEVICE_STATE_SEND:
      prepareTxFrame(appPort);
      LoRaWAN.send();
      deviceState = DEVICE_STATE_CYCLE;
      break;

    case DEVICE_STATE_CYCLE:
      txDutyCycleTime = appTxDutyCycle;
      LoRaWAN.cycle(txDutyCycleTime);
      deviceState = DEVICE_STATE_SLEEP;
      break;

    case DEVICE_STATE_SLEEP:
      LoRaWAN.sleep(loraWanClass);
      break;

    default:
      deviceState = DEVICE_STATE_INIT;
      break;
  }
}
