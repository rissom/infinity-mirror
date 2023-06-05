
int counter = 0;
int counter2 = 0;
int r,g,b = 0;

boolean direction =true;
void ferdiYtest() {
  for( int x = 0; x < MATRIXWIDTH; x++) {
    for( int y = 0; y < MATRIXHEIGHT; y++) {
      if (counter == y) {
        //leds[ XY(x, y)]  = CRGB::White;
        setColor(x,y,255,255,255);
      } else {
        //leds[ XY(x, y)]  = CRGB::Black;
        setColor(x,y,0,0,0);
      }
    }
  }
  bitbang();
  if (direction) counter++; else counter--;
  if (counter>=MATRIXHEIGHT) {
    counter = MATRIXHEIGHT-2;
    direction=!direction;
  }
  if (counter<0) {
    counter = 1;
    direction=!direction;
  }
  delay(100);
}