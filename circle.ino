void circle(int lednum){

  //set retrowave sun colours over square
  for(uint16_t i=0; i < 32; i++){
    leds[i] = 0xA50675; //purple
  }
  for(uint16_t i = 31; i < 96; i++){
    leds[i] = 0xFF0000; //red
  }
  for(uint16_t i = 95; i < 192; i++){
    leds[i] = 0xB51D05; //orange
  }
  for(uint16_t i = 191; i < 256; i++){
    leds[i] = 0xFFFF27; //yellow 
  }

  uint16_t x = 0;
  uint16_t y = 0;
  //uint16_t x0 = 8;
  //uint16_t y0 = 8;
  uint16_t radius = 7;

  //clear circle negative space
  /*for(uint16_t i = 0; i < 256; i++){
    if ( (x >= 0 & x <= 7) (y >= 0 & y <= 7)){
      if(round( sqrt(  ) ){
        leds[i] = 0x000000;
      }
      }
    }
  for(uint16_t i = 0; i < 256; i++){
    if ( (x >= 8 & x <= 15) (y >= 0 & y <= 7)){
      
        leds[i] = 0x000000;
      }
    }
  for(uint16_t i = 0; i < 256; i++){
    if ( (x >= 0 & x <= 7) (y >= 8 & y <= 15)){
      
        leds[i] = 0x000000;
      }
    }
  for(uint16_t i = 0; i < 256; i++){
    if ( (x >= 8 & x <= 15) (y >= 8 & y <= 15)){
      
        leds[i] = 0x000000;
      }
    }
    x++;
    y++;
  }*/
  //FastLED.addLeds<WS2812B, 5, GRB>(leds, lednum).setCorrection(TypicalSMD5050); 
  //FastLED.setBrightness(BRIGHTNESS);
  //FastLED.setTemperature(DirectSunlight);
  FastLED.show();

  /*
  //radius of circle
  uint8_t r = 8;
  //origin of circle
  uint8_t a = 8;
  uint8_t b = 8;
  uint8_t x = 0;
  uint8_t y = 0;

  for (x = 0; x < 16; x++){
    for(y = 0; y < 16; y++){}
      if((x <= (a + r) && x >= (a - r)) && (y <= (b + r) && y >= (b - r))){
        leds[XY(x,y,16,16)] = 0xB51D05; //orange
      }
    }
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, lednum).setCorrection(TypicalSMD5050); 
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setTemperature(DirectSunlight);
  FastLED.show();
  delay(1000);*/
}