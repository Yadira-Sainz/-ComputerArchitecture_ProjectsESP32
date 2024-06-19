#include <Arduino.h>

#include <Wire.h>

#define LM35 18

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  int lectura = analogRead(LM35); // Lee el valor del sensor
  float voltaje = lectura * (3.3 / 4095.0); // Convierte el valor leído a voltaje
  float temperatura = voltaje * 100; // Convierte el voltaje a temperatura en grados Celsius

  Serial.print("Temperatura: "); 
  Serial.print(temperatura); 
  Serial.println(" °C"); 

  delay(1000); // Espera un segundo antes de la próxima lectura
}
