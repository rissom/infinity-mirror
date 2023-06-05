void thorseColor(int ms) {
  for( int x = 0; x < MATRIXWIDTH; x++) {
      for( int y = 0; y < MATRIXHEIGHT; y++) {
        r =  (int) ((cos16(((ms*30) + (x*560) + (y*300)        ) % 65536)  ) / 256) + 127;
        g =  (int) ((cos16(((ms*30) + (x*560) + (y*300) + 21845 ) % 65536)  ) / 256) + 127;
        b =  (int) ((cos16(((ms*30) + (x*560) + (y*300) + 43691 ) % 65536)  ) / 256) + 127;
        //leds[ XY(x, y)]  = ( r, g, b);
        setColor(x,y,r,g,b);
      }
  }     
  bitbang();
}