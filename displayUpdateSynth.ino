/* Display update with vaporwave sun colour theme*/
void displayUpdateSynth(){
  for(int i = 0; i < xres; i++){  // 16
    for(int j = 0; j < yres; j++){  //16
      if(j <= g_Intensity[i]){                                // Light everything within the intensity range
        if(j < 2){ //for rows 1-2 set to purple
          if(j%2 == 0){ // if Y axis value count is even (serpentine value flipping)
            leds[(xres*(j+1))-i-1] = 0xA50675;
          }
          else{ // if Y axis value count is odd (serpentine value flipping)
            leds[(xres*j)+i] = 0xA50675;
          }
        }
        else if (j < 6 && j > 1){ //for rows 3-6 set to red
          if(j%2 == 0){ // if Y axis value count is even (serpentine value flipping)
            leds[(xres*(j+1))-i-1] = 0xFF0000;
          }
          else{ // if Y axis value count is odd (serpentine value flipping)
            leds[(xres*j)+i] = 0xFF0000;
          }
        }
        else if (j < 12 && j > 5){ //for rows 7-12 set to orange
          if(j%2 == 0){ // if Y axis value count is even (serpentine value flipping)
            leds[(xres*(j+1))-i-1] = 0xB51D05;
          }
          else{ // if Y axis value count is odd (serpentine value flipping)
            leds[(xres*j)+i] = 0xB51D05;
          }
        }
        else{ //for rows 12-16 set to yellow
          if(j%2 == 0){ // if Y axis value count is even (serpentine value flipping)
            leds[(xres*(j+1))-i-1] = 0xFDC00B;
          }
          else{ // if Y axis value count is odd (serpentine value flipping)
            leds[(xres*j)+i] = 0xFDC00B;
          }
        }

      }
      else{                                                  // Everything outside the range goes dark by setting to black
        if(j%2 == 0){
          leds[(xres*(j+1))-i-1] = 0x000000; 
        }
        else{
          leds[(xres*j)+i] = 0x000000;
        }
      }
    }
  }
}