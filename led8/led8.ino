#include <Adafruit_NeoPixel.h>

#define LED_PIN    6       // Digital pin connected to the LED strip
#define LED_COUNT  8       // Number of LEDs in the strip

// Declare our NeoPixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize the strip object (must be done before using it)
  strip.begin();
  // Turn off all the LEDs to start
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Example 1: Turn on each LED one by one with different colors
  for(int i=0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0)); // Red color
    strip.show();
    delay(500);
  }

  delay(1000);

  // Example 2: Turn off each LED one by one
  for(int i=0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0)); // Turn off LED
    strip.show();
    delay(500);
  }

  delay(1000);

  // Example 3: Set LEDs to different colors
  strip.setPixelColor(0, strip.Color(255, 0, 0)); // Red
  strip.setPixelColor(1, strip.Color(0, 255, 0)); // Green
  strip.setPixelColor(2, strip.Color(0, 0, 255)); // Blue
  strip.setPixelColor(3, strip.Color(255, 255, 0)); // Yellow
  strip.setPixelColor(4, strip.Color(0, 255, 255)); // Cyan
  strip.setPixelColor(5, strip.Color(255, 0, 255)); // Magenta
  strip.setPixelColor(6, strip.Color(255, 255, 255)); // White
  strip.setPixelColor(7, strip.Color(128, 0, 128)); // Purple
  strip.show();

  delay(3000);
}
