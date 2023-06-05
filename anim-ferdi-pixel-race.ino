
void ferdiPixelRace_init() {
  for (int i=0;i<MATRIXWIDTH*MATRIXHEIGHT;i++) {
    if (random(0,101)<5) {
      leds[i*3] = 255;
    } else {
      leds[i*3] = 0;
    }
  }
}

void ferdiPixelRace() {
  int dimmValue = 150;
  for( int x = 0; x < MATRIXWIDTH; x++) {
    for( int y = 0; y < MATRIXHEIGHT; y++) {
      if (getR(x, y) == 255  ) { // pixel weiss?
        boolean newPosOK = false;
        while (!newPosOK) {
          int offsetX = random(0,3)-1;
          int offsetY = random(0,3)-1;
          int posX = x+offsetX;
          if (posX<0) posX = MATRIXWIDTH-1;
          if (posX>MATRIXWIDTH-1) posX=0;
          int posY = y +offsetY;
          if (posY<0) posY = MATRIXHEIGHT-1;
          if (posY>MATRIXHEIGHT-1) posY=0;
          if (getR(posX, posY) != 255) {
            setColor(posX,posY,255,255,255);
            //leds[ XY(posX, posY)] = CRGB::White;
            setColor(x,y,254,254,254);
            //leds[ XY(x, y)]  = ( 254, 254, 254 );
            newPosOK = true;
          }
        }
      } else {
        byte newCol = getR(x, y);
        if (newCol!=255) {
          if (newCol<dimmValue) newCol =0; else newCol=newCol-dimmValue;
        
          //leds[ XY(x, y)]  = ( newCol, newCol, newCol);
           setColor(x,y,newCol, newCol, newCol);
        }
      }
    }
  }
  delay(50);
  bitbang();
}