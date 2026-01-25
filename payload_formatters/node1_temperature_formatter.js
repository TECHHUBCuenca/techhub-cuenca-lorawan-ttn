/**
 * Payload Formatter - Nodo 1 (Temperatura)
 * Dispositivo: HELTEC WiFi LoRa 32
 * Variable: Temperatura
 * Unidad: °C
 * Codificación: int16 (°C × 10)
 */

function decodeUplink(input) {

  // Verificar tamaño esperado
  if (input.bytes.length !== 2) {
    return {
      errors: ["Tamaño de payload inválido"]
    };
  }

  // Reconstrucción int16 (big-endian)
  let raw = (input.bytes[0] << 8) | input.bytes[1];

  // Conversión a temperatura real
  let temperature = raw / 10.0;

  return {
    data: {
      temperature_c: temperature
    }
  };
}

