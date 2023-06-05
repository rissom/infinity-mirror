#include <FastLED.h>

#define EDGELENGTH 28
#define SEGMENTS 4
#define MATRIXHEIGHT 4
#define MATRIXWIDTH ( EDGELENGTH * SEGMENTS )
#define BRIGHTNESS 255
#define NUM_LEDS (MATRIXWIDTH * MATRIXHEIGHT)
#define COLOR_ORDER GRB
#define CHIPSET     NEOPIXEL

volatile uint8_t leds[ NUM_LEDS * 3 ];

float pi = 3.14159;

void setColor(uint8_t x, uint8_t y, uint8_t r, uint8_t g,uint8_t b) {
  uint16_t index = (y*MATRIXWIDTH+x)*3;
  #ifndef COLOR_ORDER
  leds[index] = r;
  index++;
  leds[index] = g;
  index++;
  leds[index] = b;
  #error "kann nicht sein"
  #else
  leds[index] = g;
  index++;
  leds[index] = r;
  index++;
  leds[index] = b;
  #endif
}
uint8_t getR(uint8_t x, uint8_t y) {
  return leds[(y*MATRIXWIDTH+x)*3];
}
uint8_t getG(uint8_t x, uint8_t y) {
  return leds[(y*MATRIXWIDTH+x)*3+1];
}
uint8_t getB(uint8_t x, uint8_t y) {
  return leds[(y*MATRIXWIDTH+x)*3+2];
}

void play_animation(void *init_function(), void *anim_function(), uint32_t duration) {
  uint32_t ms = millis();
  uint32_t start = ms;
  if (init_function!=NULL) {
    (*init_function)();
  }
  while ( ms - start < duration && !(ms < start) ) { // overflow safe!
    ms = millis();
    (*anim_function)(); 
  }
}

void setup() {
  Serial.begin(115200);
  //DDRC = 1+2+4+8; // setting PORTC0..3 to output
  DDRC |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3);
}

void loop()
{ 
    play_animation(NULL, &hans70sDiscoTerror,4000 );
    
    play_animation(&ferdiPixelRace_init, &ferdiPixelRace,4000 );
    
    play_animation(NULL, &ferdiYtest,4000 );
    
    play_animation(NULL, &thorseGreenTunnel,4000 );
    
    play_animation(NULL, &thorseColor,4000 );
}
