/* Heartbeat function that blinks the built in LED (pin 13 on an arduino uno) whilst code is running.
	 This code uses non-blocking delays (millis() compare) so that the function won't stop other code from
	 executing. The heartbeat visually indicates if code is executing on the microcontroller, which can be useful for debugging.*/

void heartbeat() { 
	// defining these as statics within the function rather than globals to limit them to this function
	static const long unsigned heart_beat_freq = 750; // time(milliseconds) of heart beat frequency 
	static long unsigned heart_beat_on_off_time = heart_beat_freq/2; // the time the LED is on and off - 1/2 frequency 
	static long unsigned last_heart_beat_time;   // time in milliseconds of last heart beat status change 
	static bool heart_beat_status = HIGH;        // current status of heart beat, start high 

	if (millis() - last_heart_beat_time >= heart_beat_on_off_time) { 
	  // time to swap status of the heart beat LED and update it 
	  last_heart_beat_time = millis(); 
	  heart_beat_status = !heart_beat_status;           // invert current heart beat status value 
	  digitalWrite(heart_beat_pin, heart_beat_status);  // update LED with new status 
	} 
} 