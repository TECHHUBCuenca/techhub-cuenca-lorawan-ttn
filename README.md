# 🌐 TECHHUB Cuenca  
## Comunidad LoRaWAN – The Things Network

<p align="center">
  <strong>Repositorio técnico oficial</strong><br>
  Comunidad académica y colaborativa de IoT y LoRaWAN en Cuenca – Ecuador
</p>

---

## 📌 Descripción general

**TECHHUB Cuenca** es una iniciativa que nace como un **proyecto universitario**, impulsado por estudiantes y docentes con interés en el desarrollo de **tecnologías IoT abiertas y colaborativas**.

Cuenca es una ciudad en constante crecimiento, con avances importantes en distintos ámbitos; sin embargo, actualmente **no existe una red LoRaWAN pública ni una comunidad local activa** que promueva el uso de este tipo de tecnologías.  
Esta ausencia limita el desarrollo de proyectos relacionados con:

- 🏙️ Smart Cities  
- 🌱 Agricultura inteligente  
- 🌎 Monitoreo ambiental  
- 🔋 Soluciones IoT de bajo consumo  

Ante este escenario, surge la necesidad de **sentar las bases de una comunidad local**, que permita difundir conocimiento, formar talento técnico y fomentar el uso de tecnologías abiertas como **The Things Network (TTN)**, creando un espacio de colaboración entre estudiantes, instituciones y futuros actores de la ciudad.

---

## 🧩 Visión general del proyecto

Para comprender de forma global el alcance de esta iniciativa, a continuación se presenta una vista general del proyecto, donde se integran tanto los componentes técnicos como los elementos comunitarios, académicos y organizativos que conforman TECHHUB Cuenca.


El siguiente diagrama muestra una vista integral del proyecto **TECHHUB Cuenca**, incluyendo los componentes técnicos, la infraestructura en la nube, el repositorio, el sitio web, los canales oficiales y el enfoque comunitario y académico.

![Diagrama general del proyecto TECHHUB Cuenca](docs/structure_project.png)

---

## 🎯 Objetivo de la comunidad

El objetivo principal de esta iniciativa es **crear la primera comunidad de The Things Network en la ciudad de Cuenca**, dando el primer paso hacia el despliegue progresivo de **infraestructura y gateways LoRaWAN públicos**, orientados al beneficio de la ciudad y sus habitantes.

A corto y mediano plazo, la comunidad busca:

- Ser un **punto de encuentro técnico y colaborativo**
- Facilitar el aprendizaje y la experimentación con tecnologías LoRaWAN
- Promover casos de uso reales en distintos ámbitos urbanos y rurales

A largo plazo, el objetivo es apoyar el desarrollo de una ciudad con **mejor integración tecnológica**, donde la comunidad actúe como un actor activo que aporte:

- Conocimiento
- Documentación
- Soporte técnico
- Acompañamiento en la adopción de soluciones IoT abiertas y sostenibles

---

## 📂 Estructura del repositorio

El repositorio se organiza de la siguiente manera:

```text
nodes/                Ejemplos de nodos LoRaWAN (sensores)
gateways/             Documentación y uso de gateways LoRaWAN
payload_formatters/   Decodificación de payloads en TTN
performance_tests/    Pruebas de alcance y rendimiento (pendiente)
docs/                 Documentación general del repositorio
```

## 🚀 Accesos rápidos

- 📡 [Nodos LoRaWAN](nodes/)
- 🌉 [Gateways](gateways/)
- 🔁 [Payload Formatters](payload_formatters/)
- 📄 [Documentación](docs/)

---

## 🧩 Contenido principal

| Módulo | Descripción |
|------|-------------|
| **Nodos** | Nodos sensores LoRaWAN basados en HELTEC WiFi LoRa 32 |
| **Gateways** | Uso de gateways LoRaWAN y conexión con TTN |
| **Payload Formatters** | Decodificación de datos Uplink en TTN |
| **Pruebas** | Evaluación de alcance y rendimiento (futuro) |

---

## 🌐 Infraestructura utilizada

| Componente | Detalle |
|-----------|--------|
| **Tecnología** | LoRaWAN |
| **Servidor de red** | The Things Network (TTN) |
| **Región** | US915 |
| **Gateway** | Heltec HT-M7603 |
| **Modo gateway** | Packet Forwarder |
| **Conectividad** | Wi-Fi / Ethernet |
| **Servidor LNS** | `nam1.cloud.thethings.industries` |

---

## 🏗️ Arquitectura técnica LoRaWAN

El siguiente diagrama ilustra la **arquitectura técnica LoRaWAN** utilizada en el proyecto, mostrando el flujo de datos desde los nodos sensores hasta la plataforma en la nube de **The Things Network (TTN)**.

![Arquitectura LoRaWAN TECHHUB Cuenca](docs/structure_lorawan.png)

Con esta arquitectura, el proyecto establece una base técnica funcional sobre la cual se construyen tanto los recursos del repositorio como las actividades comunitarias y académicas asociadas.

---

## 🔗 Enlaces oficiales (por definir / en construcción)

Estos enlaces se dejarán activos una vez la comunidad esté publicada oficialmente.

- 🌍 **Sitio web oficial**:  
  `https://techhubcuenca.tjdariox.com`

- 💻 **Repositorio GitHub**:  
  Este repositorio

- 🛰️ **The Things Network – Comunidad**:  
  `https://www.thethingsnetwork.org/community/[por-definir]`

- 💬 **Canales de la comunidad**:
  - Discord: `https://discord.gg/jvPnEqEu`
  - Correo de contacto: `[por-definir]`

---


## 👥 Comunidad y colaboración

Este proyecto se desarrolla de forma colaborativa, dentro de un entorno académico, promoviendo:

- Trabajo en equipo  
- Uso de tecnologías abiertas  
- Documentación clara y reutilizable  
- Aprendizaje práctico  

Las contribuciones futuras serán bienvenidas conforme la comunidad crezca.

---


## 📄 Licencia

Este proyecto se distribuye bajo la **Licencia MIT**, permitiendo su uso, modificación y redistribución con fines educativos y comunitarios.

---

<p align="center">
  <em>TECHHUB Cuenca – Construyendo la primera comunidad LoRaWAN abierta de la ciudad</em>
</p>

