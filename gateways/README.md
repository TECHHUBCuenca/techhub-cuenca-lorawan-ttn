# Gateways LoRaWAN

## 📡 Descripción general
Esta carpeta documenta el uso de **gateways LoRaWAN** dentro del proyecto TECHHUB Cuenca, los cuales actúan como el punto de enlace entre los **nodos finales LoRaWAN** y el **servidor de red The Things Network (TTN)**.

El gateway no procesa ni descifra la información de la aplicación; su función principal es recibir tramas LoRa desde los nodos y reenviarlas, junto con metadatos de radiofrecuencia, hacia TTN a través de una conexión a Internet.

---

## 🧩 Rol del gateway en la arquitectura LoRaWAN
Dentro de la arquitectura LoRaWAN, el gateway cumple las siguientes funciones:

- Recibir tramas LoRa desde múltiples nodos finales
- Reenviar los paquetes al servidor de red mediante IP
- Adjuntar metadatos de radio (RSSI, SNR, canal, SF, etc.)
- Operar como un dispositivo **transparente** a nivel de aplicación

El gateway **no** gestiona claves, **no** descifra payloads y **no** toma decisiones de red.

---

## 🏗️ Gateway utilizado en el proyecto
Para el desarrollo del proyecto se emplea el **gateway LoRaWAN Heltec HT-M7603**, un gateway comercial multicanal compatible con The Things Network (TTN).

Características relevantes:
- Modelo: **Heltec HT-M7603**
- Arquitectura multicanal LoRaWAN
- Conectividad IP mediante **Wi-Fi o Ethernet**
- Soporte para modo **Packet Forwarder**
- Integración directa con TTN


---

## ☁️ Conectividad a la nube (TTN)
El gateway Heltec HT-M7603 opera en **modo Packet Forwarder**, actuando como un puente transparente entre la red LoRaWAN y la infraestructura en la nube de The Things Network.

La comunicación del gateway hacia TTN se realiza mediante una conexión IP activa, enviando los paquetes recibidos al servidor de red:

```text
nam1.cloud.thethings.industries
```

Este servidor corresponde al cluster de Norteamérica (NAM1) de The Things Network, encargado de procesar los mensajes uplink provenientes del gateway.

---

## 🌎 Parámetros de operación
Los gateways utilizados en el proyecto operan bajo los siguientes parámetros:

- **Región**: US915
- **Sub-banda**: US915_0 (canales 0–7)
- **Modo de operación**: LoRaWAN estándar
- **Servidor de red**: The Things Network (TTN)

> ⚠️ Es obligatorio que la región y sub-banda del gateway coincidan exactamente con las configuradas en los nodos finales.

---

## ⚙️ Configuración básica en TTN
A nivel de TTN, el gateway debe estar:

- Registrado en la consola de TTN
- Asociado a la región correcta (US915)
- En estado **Online**
- Enlazado al servidor de red correspondiente

La configuración detallada del firmware del gateway queda fuera del alcance de este repositorio.

---



## 📄 Licencia
La documentación de gateways se distribuye bajo la licencia MIT.

