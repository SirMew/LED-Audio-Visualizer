void getSamples(){
  for(int i = 0; i < SAMPLES; i++){
    g_vReal[i] = analogRead(MIC_IN); //read sample 
    Serial.println(g_vReal[i]);
    g_vImag[i] = 0;
  }

  //FFT
  FFT.windowing(g_vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.compute(g_vReal, g_vImag, SAMPLES, FFT_FORWARD);
  FFT.complexToMagnitude(g_vReal, g_vImag, SAMPLES);

  //Update Intensity Array
  for(int i = 2; i < (xres*g_displacement)+2; i+=g_displacement){
    g_vReal[i] = constrain(g_vReal[i],0 ,2047);            // set max value for input data
    g_vReal[i] = map(g_vReal[i], 0, 2047, 0, yres);        // map data to fit our display

    g_Intensity[(i/g_displacement)-2] --;                      // Decrease displayed value
    if (g_vReal[i] > g_Intensity[(i/g_displacement)-2])          // Match displayed value to measured value
      g_Intensity[(i/g_displacement)-2] = g_vReal[i];
  }
}