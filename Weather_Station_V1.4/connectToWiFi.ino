//------------------------------------------------------------------------------------------------------------
/////////////////////////Following function connects esp8266 to wifi access point/////////////////////////////
//------------------------------------------------------------------------------------------------------------
bool connectToWiFi()
{
  if(DEBUG){
    Serial.println("connectToWiFi");
  }  
  String cmd = F("AT+CWJAP=\"");
  cmd += network;
  cmd += F("\",\"");
  cmd += password;
  cmd += F("\"");
  esp8266Module.println(cmd);
  delay(15000);
  
  if (esp8266Module.find("OK"))
  {
    if(DEBUG){
      Serial.println("Connected to Access Point");
    }  
    return true;
  }
  else
  {
    if(DEBUG){
      Serial.println("Could not connect to Access Point");
    }  
    return false;
  }

}
