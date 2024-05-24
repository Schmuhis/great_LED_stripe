#include <Adafruit_NeoPixel.h>

#define LED_PIN    5
#define LED_COUNT  300
#define SNAKE_LENGTH_INIT 25
#define TARGET_LENGTH 150
#define BRIGHTNESS 20
#define SPEED_INIT 30

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

uint32_t white = strip.Color(255, 255, 255);
uint32_t green = strip.Color(255, 0, 0);
uint32_t red = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t rose_quartz = strip.Color(188, 235, 186);
uint32_t background = strip.Color(207, 156, 216);
uint32_t schmaddes = strip.Color(128, 232, 30);
uint32_t snake_colour = strip.Color(1, 144, 122);

long s;

int i = 0;
int speed;
int snake_length;

void init_background() {
  for(int k=0; k < LED_COUNT; k++) {
    strip.setPixelColor(k, schmaddes);
  }
  strip.setPixelColor(s, red);
}

void snake() {
  if (i == s) {
    long r;
    if (snake_length < TARGET_LENGTH) {
        snake_length++;
        speed--;
        r = random(LED_COUNT - snake_length);
        s = (i + r) % LED_COUNT;
        strip.setPixelColor(s, red);
    } else if (snake_length == TARGET_LENGTH) {
        snake_length++;
        speed--;
        r = random(LED_COUNT - snake_length);
        s = i + r;
        s = (i + r) % LED_COUNT;
        strip.setPixelColor(s, blue);
    } else {
        snake_length = SNAKE_LENGTH_INIT;
        speed = SPEED_INIT;
        r = random(LED_COUNT - snake_length);
        s = (i + r) % LED_COUNT;
        strip.setPixelColor(s, red);
    }
  }
  if (i < LED_COUNT) {
    strip.setPixelColor(i, schmaddes);
    int j = 1;
    for (j; j <= snake_length; j++) {
      strip.setPixelColor((i + j) % LED_COUNT, snake_colour);
    }
    strip.show();
    if (speed <= 0) {
        speed = 1;
    }
    delay(speed);
    i++;
  } else {
    i = 0;
  }
}

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  init_background();
  strip.show();
  speed = SPEED_INIT;
  snake_length = SNAKE_LENGTH_INIT;
  s = random(LED_COUNT);
}

void loop() {
  snake();
}

