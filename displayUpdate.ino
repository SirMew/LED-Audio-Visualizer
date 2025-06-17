void displayUpdate(){
  int color = 0;
  for(int i = 0; i < xres; i++){
    for(int j = 0; j < yres; j++){
      if(j <= g_Intensity[i]){                                // Light everything within the intensity range
        if(j%2 == 0){
          leds[(xres*(j+1))-i-1] = CHSV(color, 255, BRIGHTNESS);
        }
        else{
          leds[(xres*j)+i] = CHSV(color, 255, BRIGHTNESS);
        }
      }
      else{                                                  // Everything outside the range goes dark
        if(j%2 == 0){
          leds[(xres*(j+1))-i-1] = CHSV(color, 255, 0);
        }
        else{
          leds[(xres*j)+i] = CHSV(color, 255, 0);
        }
      }
    }
    color += 255/xres;                                      // Increment the Hue to get the Rainbow
  }
}