//-------------------------------------------------------------------------------------------------------------
////////////////////////////////////READ THE DATA FROM SENSORS/////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------------
void read_data(void)
{
  tempc = bme.readTemperature();
    if (tempc > tempc_max) {
      tempc_max = tempc;
  }
    if (tempc_min > tempc ) {
     tempc_min = tempc;
}     

tempc = (tempc_min + tempc_max)*0.5;  // average wind temperature C per 10 minutes

     humidity = bme.readHumidity();
    
     tempf =  (tempc * 9.0)/ 5.0 + 32.0;   
     dewptf = (dewPoint(tempf, bme.readHumidity()));
     
     barompa = bme.readPressure();
     baromhpa = (barompa / 100)+(altitudepws * 0.12);  
     baromin = (baromhpa)/ 33.86;
     
     int uvLevel = averageAnalogRead(UVOUT);
     int refLevel = averageAnalogRead(REF_3V3);
     //Use the 3.3V power pin as a reference to get a very accurate output value from sensor
     float outputVoltage = 3.3 / refLevel * uvLevel;
     uvIntensity = mapfloat(outputVoltage, 0.99, 2.2, 0.0, 30.0);
     if  ( uvIntensity < 0.4 ){ 
      uvIntensity = 0; 
      }
     
     UV_convert();
  }
