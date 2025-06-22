void startupRGB(int ledNum){
  int colourVal = 0;
  long unsigned systick;
  //Loop through RGB
  while(colourVal < 4){
    for(int t=0;t<3;t++){
      if (millis() - systick >= 1000) { //non-blocking delay
        systick = millis(); 
        colourVal=colourVal+1;
        //loop through LEDs in matrix, setting all to a single a single colour
        for(int i=0;i<ledNum;i++){
        
            if (colourVal == 1){
              leds[i] = 0xFF0000; //red
            }
            else if (colourVal == 2){
              leds[i] = 0x00FF00; //green
            }
            else if (colourVal == 3){
              leds[i] = 0x0000FF; //blue
          }
        }
      FastLED.show();
      }
    }
  }
}