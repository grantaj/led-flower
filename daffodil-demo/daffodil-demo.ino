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
  daffodilEffect(10); // Create a stunning daffodil lighting effect with a speed of 10ms
}

// Function to create a daffodil lighting effect
void daffodilEffect(int speed) {
  for(int brightness = 0; brightness < 256; brightness++) {
    applyDaffodilEffect(brightness);
    strip.show();
    delay(speed);
  }

  for(int brightness = 255; brightness >= 0; brightness--) {
    applyDaffodilEffect(brightness);
    strip.show();
    delay(speed);
  }
}

// Function to apply the daffodil effect
void applyDaffodilEffect(int brightness) {
  uint32_t innerColor = colorDim(strip.Color(255, 255, 0), brightness); // Yellow for inner petals
  uint32_t outerColor = colorDim(strip.Color(255, 140, 0), brightness); // Orange for outer petals

  for(int i = 0; i < LED_COUNT / 2; i++) {
    int scaledBrightness = (brightness * (i + 1)) / (LED_COUNT / 2); // Scale brightness for blooming effect
    uint32_t newInnerColor = colorDim(innerColor, scaledBrightness);
    uint32_t newOuterColor = colorDim(outerColor, scaledBrightness);

    int left = (LED_COUNT / 2) - i - 1;
    int right = (LED_COUNT / 2) + i;
    
    if(left >= 0) strip.setPixelColor(left, newInnerColor);
    if(right < LED_COUNT) strip.setPixelColor(right, newOuterColor);
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
