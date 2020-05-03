//------------------------------------------------------------------------------------------------------------
///////////////////////////////// Get Rain data //////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------

  void getRain(void)
   {
// we only display the tip count when it has been incremented by the sensor
   cli();         //Disable interrupts
  
      rain1h = tipCount1h * Bucket_Size;
      rain24h = tipCount24h * Bucket_Size;
  
      if (raincount1h >= 120)   
      { 
// Im using 120 count for the 30 second loop time wunderground goes by 1 hour intervals (30 seconds x 120)  = 3600 seconds / 60 = 60 minutes = 1h

    tipCount1h = 0;
    raincount1h = 0;
}
 if (raincount24h >= 2879) 
      {    
    tipCount24h = 0;
    raincount24h = 0;
}
   sei();         //Enables interrupts
   raincount1h++;
   raincount24h++;
}
