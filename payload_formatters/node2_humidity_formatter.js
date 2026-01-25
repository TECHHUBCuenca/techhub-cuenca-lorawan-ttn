/**
 * Payload Formatter - Nodo 2 (Humedad)
 * Dispositivo: HELTEC WiFi LoRa 32
 * Variable: Humedad relativa
 * Unidad: %
 * Codificación: uint16 (% × 10)
 */

function decodeUplink(input) {

  // Verificar tamaño esperado
  if (input.bytes.length !== 2) {
    return {
      errors: ["Tamaño de payload inválido"]
    };
  }

  // Reconstrucción uint16 (big-endian)
  let raw = (input.bytes[0] << 8) | input.bytes[1];

  // Conversión a humedad real
  let humidity = raw / 10.0;

  return {
    data: {
      humidity_percent: humidity
    }
  };
}

