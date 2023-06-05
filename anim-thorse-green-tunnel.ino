void thorseGreenTunnel() {
  for( int x = 0; x < MATRIXWIDTH; x++) {
      for( int y = 0; y < MATRIXHEIGHT; y++) {
        //leds[ XY(x, y)]  = CRGB::White;
         setColor(x,y, 0, 0, 0);
        if (counter == y) {
            //leds[ XY(x, y)]  = ( 0, 200, 0);
            setColor(x,y, 0, 200, 0);
        }
        if (counter2 == x % 10){
           // leds[ XY(x, y)]  = ( 0, 200, 0);
            setColor(x,y, 0, 200, 0);
        }
    }
  }
  bitbang();
  counter = (counter + 1) % 4; 
  counter2 = (counter2 + 1) % 10;
  delay(100);
}