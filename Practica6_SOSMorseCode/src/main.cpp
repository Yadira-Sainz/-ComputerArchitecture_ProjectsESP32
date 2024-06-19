#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 48

// Define the array of leds
CRGB leds[NUM_LEDS];

int ledPin = 7;
int durations[] = {200, 200, 200, 500, 500, 500, 200, 200, 200};

void flash(int duration) {
  leds[0] = CRGB::Blue;
  digitalWrite(ledPin, HIGH);  // Turn on the built-in LED
  FastLED.show();
  delay(duration);

  leds[0] = CRGB::Black;
  digitalWrite(ledPin, LOW);   // Turn off the built-in LED
  FastLED.show();
  delay(duration);
}

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  pinMode(ledPin, OUTPUT);  // Set built-in LED pin as output
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 9; i++) {
    flash(durations[i]);
    if (i == 2) {
      delay(300);
    }
  }
  delay(1000);  // wait 1 second before we start again
}