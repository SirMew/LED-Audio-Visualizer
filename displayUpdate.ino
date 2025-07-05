void displayUpdate(){
  int color = 0;
  for(int i = 0; i < xres; i++){  // 16
    for(int j = 0; j < yres; j++){  //16
      if(j <= g_Intensity[i]){                                // Light everything within the intensity range
        if(j%2 == 0){ // if Y axis value count is even (serpentine value flipping)
          leds[(xres*(j+1))-i-1] = CHSV(color, 255, BRIGHTNESS); //HUE SATURATION BRIGHTNESS
        }
        else{ // if Y axis value count is odd (serpentine value flipping)
          leds[(xres*j)+i] = CHSV(color, 255, BRIGHTNESS);
        }
      }
      else{                                                  // Everything outside the range goes dark
        if(j%2 == 0){
          leds[(xres*(j+1))-i-1] = CHSV(color, 255, 0); // 0 BRIGHTNESS - BAD CODE
        }
        else{
          leds[(xres*j)+i] = CHSV(color, 255, 0);
        }
      }
    }
    color += 255/xres;                                      // Increment the Hue to get the Rainbow
  }
}