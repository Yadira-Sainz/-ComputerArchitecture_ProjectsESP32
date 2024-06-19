#include <Arduino.h>

const int ledPins[] = {4, 7, 17, 3, 10, 13};
const int numLeds = 6;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
    //delay(500);
  }
  delay(500);
}
