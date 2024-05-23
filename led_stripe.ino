#include <Adafruit_NeoPixel.h>

#define LED_PIN    5
#define LED_COUNT  300
#define NUM_COLOUR_PIXEL 25
#define BRIGHTNESS 20

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

uint32_t white = strip.Color(255, 255, 255);
uint32_t green = strip.Color(255, 0, 0);
uint32_t red = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t rose_quartz = strip.Color(188, 235, 186);
uint32_t background = strip.Color(207, 156, 216);
uint32_t schmaddes = strip.Color(128, 232, 30);

int i = 0;

void init_background() {
  for(int k=0; k < LED_COUNT; k++) {
    strip.setPixelColor(k, schmaddes);
  }
}

void snake() {
  if (i < LED_COUNT) {
    strip.setPixelColor(i, schmaddes);
    int j = 1;
    for (j; j <= NUM_COLOUR_PIXEL; j++) {
      strip.setPixelColor((i + j) % LED_COUNT, white);
    }
    strip.show();
    delay(50);
    i++;
  } else {
    i = 0;
  }
}

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  init_background();
  strip.show();
}

void loop() {
  snake();
}

