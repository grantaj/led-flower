#include <Adafruit_NeoPixel.h>

#define LED_PIN    6       // Digital pin connected to the LED strip
#define LED_COUNT  120     // Number of LEDs in the strip

// Declare our NeoPixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Function to initialize the strip
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// Main loop to create staggered pulsing effects
void loop() {
  // Staggered pulsing effect
  for(int j = 0; j < 256; j++) { // Brightness from 0 to 255
    for(int i = 0; i < LED_COUNT; i += 12) {
      int brightness = (j + (i / 12) * 32) % 256; // Create a staggered effect
      strip.setPixelColor(i, strip.Color(brightness, 0, 255 - brightness)); // Pulse between blue and magenta
      strip.setPixelColor(i + 1, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 2, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 3, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 4, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 5, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 6, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 7, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 8, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 9, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 10, strip.Color(brightness, 0, 255 - brightness)); // Next LED
      strip.setPixelColor(i + 11, strip.Color(brightness, 0, 255 - brightness)); // Next LED
    }
    strip.show();
    delay(20);
  }
}

