#include <Arduino.h>
#include <Wire.h>

#define PIR_PIN 10

void setup() {
  // Inicia la comunicación serie
  Serial.begin(115200);
  
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  // Lee el estado del sensor PIR
  int pirState = digitalRead(PIR_PIN);

  // Si el estado del PIR es HIGH, entonces hay movimiento
  if (pirState == HIGH) {
    Serial.println("Movimiento detectado!");
  } else {
    Serial.println("No se detecta movimiento.");
  }

  // Espera un segundo antes de la próxima lectura
  delay(1000);
}
