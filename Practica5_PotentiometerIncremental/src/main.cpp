#include <Arduino.h>

#define POT_PIN 5  // Cambia esto al pin al que has conectado tu potenciómetro
#define NUM_LEDS 6  // Número de LEDs

int LED_PINS[NUM_LEDS] = {4, 7, 17, 3, 10, 13};  // Pines a los que están conectados los LEDs

void setup() {
  Serial.begin(115200);  // Inicia el Monitor Serial a 115200 baudios
  pinMode(POT_PIN, INPUT);  // Configura el pin del potenciómetro como entrada
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);  // Configura los pines de los LEDs como salida
  }
}

void loop() {
  int potValue = analogRead(POT_PIN);  // Lee el valor del potenciómetro
  float normalizedValue = ((float)potValue / 4095.0) * 100.0;  // Normaliza el valor a un rango de 0 a 100
  float customMappedValue = pow(normalizedValue / 100.0, 0.2);  // Aplica una función de potencia al valor y lo mantiene en el rango de 0 a 1
  int numLedsOn = round(customMappedValue * NUM_LEDS);  // Mapea el valor a un rango de 0 a NUM_LEDS

  // Enciende los LEDs correspondientes
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i < numLedsOn) {
      digitalWrite(LED_PINS[i], HIGH);  // Enciende el LED
    } else {
      digitalWrite(LED_PINS[i], LOW);  // Apaga el LED
    }
  }

  delay(100);  // Espera un poco antes de la próxima lectura
}