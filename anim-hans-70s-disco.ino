// Demo that USES "XY" follows code below
void DrawOtherFrame( int8_t cnt, int8_t yHueDelta8, int8_t xHueDelta8)
{
  int8_t speed = 80;
  byte lineStartHue = cnt;
  byte pixelHue = lineStartHue;      
  for( byte x = 0; x < MATRIXWIDTH; x++) {
    //byte brightness = ((x & 15) == (counter & 15)) ? 255 : 0;
    byte brightness = -(x+(cnt*speed/255))<<4;
    pixelHue += xHueDelta8;
    for( byte y = 0; y < MATRIXHEIGHT; y++) {
      //leds[ XY(x, y)]  = CHSV( pixelHue, 150, brightness);
      CRGB chsv = CHSV( pixelHue, 150, brightness);
      setColor(x,y,chsv.r, chsv.g, chsv.b);
    }
  }
}
void hans70sDiscoTerror() {

    //uint32_t ms = (int32_t) (millis()/1);
    uint32_t ms = millis();
    int32_t yHueDelta32 = ((int32_t)cos16( ms * (27/1) ) * (350 / MATRIXWIDTH));
    int32_t xHueDelta32 = ((int32_t)cos16( ms * (39/1) ) * (310 / MATRIXHEIGHT));
    xHueDelta32 =  4*32768;
    yHueDelta32 = 0;
    DrawOtherFrame( ms/16, yHueDelta32 / 32768, xHueDelta32 / 32768);
    bitbang();
}
