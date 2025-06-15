// This function will return the right 'led index number' for 
// a given set of X and Y coordinates on your matrix.  
// IT DOES NOT CHECK THE COORDINATE BOUNDARIES.  
// That's up to you.  Don't pass it bogus values.
//
// Use the "XY" function like this:
//
//    for( uint8_t x = 0; x < kMatrixWidth; x++) {
//      for( uint8_t y = 0; y < kMatrixHeight; y++) {
//      
//        // Here's the x, y to 'led index' in action: 
//        leds[ XY( x, y) ] = CHSV( random8(), 255, 255);
//      
//      }
//    }

uint16_t XY( uint8_t x, uint8_t y, uint8_t kMatrixWidth, uint8_t kMatrixHeight){
  uint16_t i;
  bool kMatrixVertical = false;

  if (kMatrixVertical == false) {
    if( y & 0x01) {
      // Odd rows run backwards
      uint8_t reverseX = (kMatrixWidth - 1) - x;
      i = (y * kMatrixWidth) + reverseX;
    } else {
      // Even rows run forwards
      i = (y * kMatrixWidth) + x;
    }
  } else { // vertical positioning
    if ( x & 0x01) {
      i = kMatrixHeight * (kMatrixWidth - (x+1))+y;
    } else {
      i = kMatrixHeight * (kMatrixWidth - x) - (y+1);
    }
  }
  
  return i;
}