#include "LoRaWan_APP.h"          // Stack LoRaWAN oficial de Heltec
#include "HT_SSD1306Wire.h"       // Driver para pantalla OLED Heltec
#include <Wire.h>

// ======================================================
// ================= DISPLAY OLED =======================
// ======================================================
// El objeto 'display' ya está definido dentro
// de la librería Heltec
extern SSD1306Wire display;

// ======================================================
// ================== OTAA KEYS =========================
// ======================================================
// Identificadores OTAA asignados por TTN
// (Nodo 2 – Sensor de humedad)

uint8_t devEui[8] = {
  0x61, 0x65, 0x19, 0xCD,
  0x46, 0x77, 0x36, 0xAD
};

uint8_t appEui[8] = {
  0xFD, 0x44, 0xC1, 0x9A,
  0x4B, 0x44, 0x12, 0xE2
};

uint8_t appKey[16] = {
  0x3B, 0x4A, 0xF8, 0xF9,
  0xF4, 0x90, 0x92, 0xDE,
  0xDD, 0x4C, 0xEB, 0x59,
  0xCD, 0x2B, 0xF1, 0x68
};

// ======================================================
// ===== VARIABLES REQUERIDAS POR LA LIBRERÍA ============
// ======================================================
// Aunque se utilice OTAA, la librería exige
// la declaración de estas variables

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
uint32_t appTxDutyCycle = 1000;     // Periodo de transmisión: 1 segundo
bool overTheAirActivation = true;   // Activación OTAA
bool loraWanAdr = false;            // ADR deshabilitado
bool isTxConfirmed = false;         // Uplink no confirmado
uint8_t appPort = 3;                // Puerto de aplicación (distinto al Nodo 1)
uint8_t confirmedNbTrials = 8;

// ======================================================
// =============== FUNCIONES OLED =======================
// ======================================================

void showStatus(String line1, String line2) {
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Nodo 2 - LoRaWAN");
  display.drawLine(0, 12, 127, 12);
  display.drawString(0, 20, line1);
  display.drawString(0, 34, line2);
  display.display();
}

// ======================================================
// =============== PAYLOAD UPLINK =======================
// ======================================================
// Envía humedad simulada (% * 10)

static void prepareTxFrame(uint8_t port) {

  // Humedad simulada entre 30 % y 90 %
  float hum = 30.0 + random(0, 600) / 10.0;
  uint16_t hum_int = hum * 10;

  // Payload binario (big endian)
  appData[0] = (hum_int >> 8) & 0xFF;
  appData[1] = hum_int & 0xFF;
  appDataSize = 2;

  Serial.print("Nodo 2 TX -> Humedad: ");
  Serial.print(hum);
  Serial.println(" %");

  showStatus("TX Humedad", String(hum) + " %");
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

  Serial.println("Nodo 2 iniciado - OTAA");
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
      Serial.println("Nodo 2 -> JOIN OTAA...");
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
