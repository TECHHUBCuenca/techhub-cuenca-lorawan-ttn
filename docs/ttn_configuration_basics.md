# Configuración básica en The Things Network (TTN)

## 📡 Introducción
Este documento describe los conceptos básicos para configurar aplicaciones y dispositivos en **The Things Network (TTN)** dentro del contexto del proyecto TECHHUB Cuenca.

---

## 🧩 Elementos principales en TTN

- **Application**: agrupa dispositivos finales
- **End Device**: nodo LoRaWAN
- **Gateway**: punto de acceso a la red
- **Payload Formatter**: decodifica datos uplink

---

## 🔑 Activación de dispositivos
Los nodos del proyecto utilizan:

- Método de activación: **OTAA**
- Clase de dispositivo: **Clase A**
- Región: **US915**

Cada dispositivo requiere:
- DevEUI
- AppEUI / JoinEUI
- AppKey

---

## 🔁 Flujo de datos
1. Nodo transmite uplink
2. Gateway recibe la trama
3. TTN procesa el mensaje
4. Payload Formatter decodifica los datos
5. Aplicación recibe información legible

---

## 📌 Nota
La configuración detallada de cada nodo se documenta dentro de la carpeta `nodes/`.

