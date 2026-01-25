# Nodos LoRaWAN – HELTEC WiFi LoRa 32

## 📡 Descripción general
Esta carpeta contiene ejemplos de nodos LoRaWAN implementados sobre placas **HELTEC WiFi LoRa 32 (ESP32)**, configurados para operar dentro de una red **LoRaWAN** utilizando **The Things Network (TTN)** como servidor de red.

Los nodos están diseñados para funcionar bajo una **topología estrella**, donde los dispositivos finales se comunican directamente con un **gateway LoRaWAN** conectado a Internet, sin comunicación directa entre nodos.

---

## 🧩 Hardware utilizado
- Placa: **HELTEC WiFi LoRa 32**
- Microcontrolador: ESP32
- Transceptor LoRa: Semtech SX1262
- Pantalla: OLED integrada
- Antena: LoRa externa
- Alimentación: USB / batería LiPo

---

## 🏗️ Arquitectura de red
- **Tecnología**: LoRaWAN
- **Servidor de red**: The Things Network (TTN)
- **Gateway**: Gateway LoRaWAN con conexión a Internet
- **Topología**: Estrella
- **Clase de dispositivo**: Clase A
- **Método de activación**: OTAA (Over-The-Air Activation)

---

## 🌎 Parámetros LoRaWAN
Los nodos están configurados con los siguientes parámetros comunes:

- **Región**: US915
- **Sub-banda**: US915_0 (canales 0–7)
- **ADR**: Deshabilitado
- **Uplink confirmado**: No
- **Formato de payload**: Binario
- **Frecuencia de envío**: 1 segundo (configurable)

> ⚠️ Es imprescindible que el gateway y los nodos estén configurados en la **misma región y sub-banda**.

---

## 💻 Entorno de desarrollo

### Software requerido
- Arduino IDE
- Drivers USB–UART (CP210x)
- Soporte para placas HELTEC ESP32
- Librerías HELTEC ESP32 Dev-Boards

---

## 🔧 Configuración del Arduino IDE

### 1️⃣ Instalar soporte para placas HELTEC
En **Archivo → Preferencias → URLs adicionales**, agregar:

```text
https://resource.heltec.cn/download/package_heltec_esp32_index.json

### 2️⃣ Instalar librerías necesarias

Luego, en el **Gestor de placas**, instalar:

- Heltec ESP32 Series Dev-Boards

Desde el **Gestor de librerías**, instalar:

- Heltec ESP32 Dev-Boards  
- HT_SSD1306Wire

---

### 3️⃣ Selección de placa y parámetros (Tools)

Configurar en el menú **Tools** del Arduino IDE:

```text
Board: Heltec WiFi LoRa 32 (V3)
CPU Frequency: 240MHz
Flash Size: 8MB
Upload Speed: 921600
Port: (puerto correspondiente)
```

## 🔑 Configuración en TTN (OTAA)

Para cada nodo se deben registrar en TTN los siguientes identificadores:

- DevEUI

- AppEUI / JoinEUI

- AppKey

Estos valores se copian directamente en el código del nodo (.ino) y son utilizados durante el proceso de Join OTAA.

Cada nodo utiliza un Application Port (AppPort) distinto para diferenciar el tipo de dato transmitido.

## 📂 Ejemplos disponibles

### Nodo 1 – Temperatura

Ruta:

```text
sensor_node/
```


- Simula el envío de temperatura (°C × 10)

- AppPort: 2

- Payload: 2 bytes (big-endian)

### Nodo 2 – Humedad

Ruta:

```text
sensor_node/
```

- Simula el envío de humedad (% × 10)

- AppPort: 3

- Payload: 2 bytes (big-endian)

## 📌 Notas importantes

- Estos nodos no utilizan LoRa P2P, únicamente LoRaWAN.

- No existe comunicación directa entre nodos.

- El gateway actúa como puente transparente hacia TTN.

- Los ejemplos están pensados con fines académicos y demostrativos.


