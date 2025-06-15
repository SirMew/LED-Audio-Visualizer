void heart_beat() { 
	if (millis() - last_heart_beat_time >= heart_beat_on_off_time) { 
	  // time to swap status of the heart beat LED and update it 
	  last_heart_beat_time = millis(); 
	  heart_beat_status = !heart_beat_status;           // invert current heart beat status value 
	  digitalWrite(heart_beat_pin, heart_beat_status);  // update LED with new status 
	} 
} 
