void getSamples(){
  for(int i = 0; i < SAMPLES; i++){
    vReal[i] = analogRead(MIC_IN); //read sample 
    Serial.println(vReal[i]);
    vImag[i] = 0;
  }

  //FFT
  FFT.windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.complexToMagnitude(vReal, vImag, SAMPLES);

  //Update Intensity Array
  for(int i = 2; i < (xres*displacement)+2; i+=displacement){
    vReal[i] = constrain(vReal[i],0 ,2047);            // set max value for input data
    vReal[i] = map(vReal[i], 0, 2047, 0, yres);        // map data to fit our display

    Intensity[(i/displacement)-2] --;                      // Decrease displayed value
    if (vReal[i] > Intensity[(i/displacement)-2])          // Match displayed value to measured value
      Intensity[(i/displacement)-2] = vReal[i];
  }
}