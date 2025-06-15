void colourCalibrate(int ledNum){
  int colourVal = 0;
  //Loop through RGB
  for(int t=0;t<9;t++){
    colourVal=colourVal+1;
    //loop through LEDs in matrix, setting all to a single a single colour
    for(int i=0;i<ledNum;i++){
    
      if (colourVal == 1){
        leds[i] = 0xFF0000; //red
      }
      else if (colourVal == 2){
        leds[i] = 0xB51D05; //orange
      }
      else if (colourVal == 3){
        leds[i] = 0xFFFF27; //yellow 
      }
      else if (colourVal == 4){
        leds[i] = 0x24AD2D; //green
      }
      else if (colourVal == 5){
        leds[i] = 0x32E8FD; //cyan
      }
      else if (colourVal == 6){
        leds[i] = 0x0613EA; //blue
      }
      else if (colourVal == 7){
        leds[i] = 0xD13189; //purple
      }
      else if (colourVal == 8){
        leds[i] = 0xFFFFFF; //white
      }
    }
    // FastLED provides these pre-conigured incandescent color profiles:
  //     Candle, Tungsten40W, Tungsten100W, Halogen, CarbonArc,
  //     HighNoonSun, DirectSunlight, OvercastSky, ClearBlueSky,
  // FastLED provides these pre-configured gaseous-light color profiles:
  //     WarmFluorescent, StandardFluorescent, CoolWhiteFluorescent,
  //     FullSpectrumFluorescent, GrowLightFluorescent, BlackLightFluorescent,
  //     MercuryVapor, SodiumVapor, MetalHalide, HighPressureSodium,
  // FastLED also provides an "Uncorrected temperature" profile
  //    UncorrectedTemperature;
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050); 
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.setTemperature(DirectSunlight);
    FastLED.show();
    delay(1000);
  }
}