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

// Main loop to create blooming effects
void loop() {
  // Blooming effect with rainbow colors
  for(int i=0; i < LED_COUNT / 2; i++) {
    setBloom(i, strip.Color(255, 0, 0), 30); // Red bloom
    setBloom(i, strip.Color(0, 255, 0), 30); // Green bloom
    setBloom(i, strip.Color(0, 0, 255), 30); // Blue bloom
    setBloom(i, strip.Color(255, 255, 0), 30); // Yellow bloom
    setBloom(i, strip.Color(0, 255, 255), 30); // Cyan bloom
    setBloom(i, strip.Color(255, 0, 255), 30); // Magenta bloom
  }
}

// Function to create a blooming effect
void setBloom(int center, uint32_t color, int delayTime) {
  int maxDistance = LED_COUNT / 2;

  // Light up from the center outwards
  for(int d=0; d <= maxDistance; d++) {
    int left = center - d;
    int right = center + d;
    
    if(left >= 0) strip.setPixelColor(left, color);
    if(right < LED_COUNT) strip.setPixelColor(right, color);
    strip.show();
    delay(delayTime);
  }

  // Fade out from the center outwards
  for(int d=0; d <= maxDistance; d++) {
    int left = center - d;
    int right = center + d;
    
    if(left >= 0) strip.setPixelColor(left, 0); // Turn off LED
    if(right < LED_COUNT) strip.setPixelColor(right, 0); // Turn off LED
    strip.show();
    delay(delayTime);
  }
}
