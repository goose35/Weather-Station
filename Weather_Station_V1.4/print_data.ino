//------------------------------------------------------------------------------------------------------------
/////////////////////////////////PRINT DATA IN SERIAL MONITOR/////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------
  
void print_data(void) 
 {
///////////////////////////////BME280////////////////////////////////
    Serial.print("Counter");
    Serial.println(counter);
    Serial.print(" ");
    Serial.print(F("BME280 = "));
    Serial.print("Temp = ");
    Serial.print(tempc);
    Serial.print(" C  ");
    Serial.print("Temp = ");
    Serial.print(tempf); 
    Serial.print(" F  ");
    Serial.print("Humidity = ");
    Serial.print(humidity); 
    Serial.print(" %  ");
    Serial.print("Pressure = ");
    Serial.print(baromhpa);
    Serial.print(" hPa  ");
    Serial.print("Pressure = ");
    Serial.print(baromin);
    Serial.print(" inHg  ");
    Serial.print(F("Approx altitude = "));
    Serial.print(bme.readAltitude(997.6)); // this should be adjusted to your local forcast http://www.mide.com/pages/air-pressure-at-altitude-calculator
    Serial.println(" m");
//////////////////////////////////////////UV///////////////////////////////////////////
    Serial.print("ML8511 = ");
    Serial.print("  UV = ");
    Serial.println(uvIntensity);
    Serial.print("output: ");
    Serial.println(refLevel);
    Serial.print("ML8511 output: ");
    Serial.println(uvLevel);
    Serial.print("ML8511 voltage: ");
    Serial.println(outputVoltage);
    Serial.print("UV Intensity: ");
    Serial.print(uvIntensity);
    Serial.println(" mW/cm^2 ");
//////////////////////////////////////Wind speed///////////////////////////////////////////
    Serial.print("WindSpeed = ");
    Serial.print(windSpeed);
    Serial.print(" mph  ");
    Serial.print(getKnots(windSpeed));
    Serial.print(" knots  ");
    Serial.print(getms(windSpeed));
    Serial.println(" m/s  ");
    Serial.print("Wind_min = ");  //Minimum wind speed
    Serial.print(wind_min);
    Serial.print(" mph ");
    Serial.print("WindAvg = "); //Average wind speed
    Serial.print(wind_avg);
    Serial.print(" mph ");
    Serial.print("WindGust = "); //Maximum wind gust speed
    Serial.print(windgustmph);
    Serial.println(" mph ");
////////////////////////////////////Wind Direction////////////////////////////////////////
    Serial.print("Wind_Direction = ");   
    getHeading(CalDirection);
    Serial.println(" ");
    ///////////////////////////////Wind Strngth Calc///////////////////////////////////////
    Serial.print("WindStrength = ");
    getWindStrength(windSpeed);
    ///////////////////////////////Rain///////////////////////////////////////////////
    Serial.print("Rain Tip Count = ");
    Serial.println(tipCount24h);
    Serial.print("Precip. Rate = ");
    Serial.print(rain1h); Serial.println(" in");
    Serial.print("Precip Accum. Total: ");
    Serial.print(rain24h); Serial.println(" in");
    
 }
