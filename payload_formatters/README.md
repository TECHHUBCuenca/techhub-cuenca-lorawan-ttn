# Payload Formatters – TECHHUB Cuenca

## 📡 Descripción
Esta carpeta contiene los **payload formatters** utilizados para decodificar los datos enviados por los nodos LoRaWAN basados en HELTEC WiFi LoRa 32 dentro de The Things Network (TTN).

Cada nodo cuenta con su propio formatter, lo que simplifica la decodificación y evita el uso de lógica condicional basada en puertos o tipos de dispositivo.

---

## 🧩 Estructura

```text
payload_formatters/
├── node1_temperature_formatter.js
└── node2_humidity_formatter.js
```

## 🔁 Funcionamiento

Los nodos transmiten datos en formato binario (2 bytes), codificados como valores enteros escalados:

- **Temperatura**: °C × 10 (`int16`)
- **Humedad**: % × 10 (`uint16`)

Los payload formatters se encargan de:

- Reconstruir el valor binario
- Aplicar el factor de escala
- Exponer los datos en formato JSON legible

---

## ⚙️ Uso en TTN

1. Ingresar a la consola de **The Things Network**
2. Seleccionar la aplicación correspondiente
3. Ir a **Payload Formatters → Uplink**
4. Copiar el código del formatter según el nodo
5. Guardar los cambios

---

## 📌 Notas

- Cada formatter está asociado a un único dispositivo final
- No se utiliza lógica basada en **AppPort**
- El enfoque es modular y fácil de mantener

