//-------------------------------------------------------------------------------------------------------------
////////////////////////////////////Get wind speed  /////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------------
void getWindSpeed(void)
  {
  // Only update the display if change greater than 45 degrees. 
  if(abs(CalDirection - LastValue) > 5)
  { 
     LastValue = CalDirection;
  }
  if(IsSampleRequired)
  {
     Rotations = 0; // Set Rotations count to 0 ready for calculations
     //sei(); // Enables interrupts
     delay (25000); // Wait 25 seconds to average wind speed
     //cli(); // Disable interrupts
     
     /* convert to mp/h using the formula V=P(2.25/T)
      V = P(2.25/25) = P * 0.9       V - speed in mph,  P - pulses per sample period, T - sample period in seconds */
     windSpeed = Rotations/3 * 0.18; // 0.18
     Rotations = 0;   // Reset count for next sample
     
     IsSampleRequired = false; 
  }
 if (windSpeed > windgustmph) {
     windgustmph = windSpeed;
}
 if (wind_min > windSpeed ) {
     wind_min = windSpeed;
}

 wind_avg = (windgustmph + wind_min) * 0.5;   // average wind speed mph per 10 minutes   
 
}
