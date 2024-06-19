#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 48

// Define the array of leds
CRGB leds[NUM_LEDS];

int ledPin = 4;  // Built-in LED on GPIO pin 4
int delayTime = 700;  // Initial delay time

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
  // Turn on both the RGB LED and the built-in LED
  leds[0] = CRGB::Red;
  digitalWrite(ledPin, HIGH);  // Turn on the built-in LED
  FastLED.show();
  delay(delayTime);

  // Turn off both the RGB LED and the built-in LED
  leds[0] = CRGB::Black;
  digitalWrite(ledPin, LOW);   // Turn off the built-in LED
  FastLED.show();
  delay(delayTime);

  // Decrease the delay time for the next cycle
  delayTime = delayTime * 0.9;  // Decrease delay time by 10%
  if (delayTime < 100) {  // If delay time is less than 100ms, reset it to 700ms
    delayTime = 700;
  }
}
