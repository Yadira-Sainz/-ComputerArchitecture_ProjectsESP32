#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 48

// Define the array of leds
CRGB leds[NUM_LEDS];

int ledPin = 9;  // Built-in LED on GPIO pin 9 for ESP32-S3

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println();
  delay(1000);
  Serial.println("Started");

  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  pinMode(ledPin, OUTPUT);  // Set built-in LED pin as output
}

void loop() {
  if (Serial.available() > 0) {  // Check if serial data is available
    char command = Serial.read(); // Read the incoming byte
    if (command == 'H') {
      leds[0] = CRGB::Red;
      digitalWrite(ledPin, HIGH);  // Turn on the built-in LED
      FastLED.show();
      delay(700);
    } else if (command == 'L') {
      leds[0] = CRGB::Black;
      digitalWrite(ledPin, LOW);   // Turn off the built-in LED
      FastLED.show();
      delay(700);
    }
  }
}
