#include <Adafruit_NeoPixel.h>

#define LED_PIN    6       // Digital pin connected to the LED strip
#define LED_COUNT  120     // Number of LEDs in the strip

// Declare our NeoPixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  breathingBloomEffect(strip.Color(0, 255, 0), 10); // Breathing bloom effect with green color
}

// Function to create a breathing bloom effect
void breathingBloomEffect(uint32_t color, int speed) {
  for(int brightness = 0; brightness < 256; brightness++) {
    applyBreathingBloom(color, brightness);
    strip.show();
    delay(speed);
  }

  for(int brightness = 255; brightness >= 0; brightness--) {
    applyBreathingBloom(color, brightness);
    strip.show();
    delay(speed);
  }
}

// Function to apply breathing and blooming effect
void applyBreathingBloom(uint32_t color, int brightness) {
  for(int i = 0; i < LED_COUNT / 2; i++) {
    int scaledBrightness = (brightness * (i + 1)) / (LED_COUNT / 2); // Scale brightness for blooming effect
    uint32_t newColor = colorDim(color, scaledBrightness);

    int left = (LED_COUNT / 2) - i - 1;
    int right = (LED_COUNT / 2) + i;
    
    if(left >= 0) strip.setPixelColor(left, newColor);
    if(right < LED_COUNT) strip.setPixelColor(right, newColor);
  }
}

// Function to adjust the brightness of a color
uint32_t colorDim(uint32_t color, int brightness) {
  uint8_t r = (uint8_t)(color >> 16);
  uint8_t g = (uint8_t)(color >>  8);
  uint8_t b = (uint8_t) color;
  
  r = (r * brightness) / 255;
  g = (g * brightness) / 255;
  b = (b * brightness) / 255;
  
  return strip.Color(r, g, b);
}
