//------------------------------------------------------------------------------------------------------------
//////////////////////////Following function sets esp8266 to station mode/////////////////////////////////////
//------------------------------------------------------------------------------------------------------------
bool changingMode()
{
    esp8266Module.println(F("AT+CWMODE=1"));
    if (esp8266Module.find("OK"))
    {
      if(DEBUG){
        Serial.println("Mode changed");
      }  
      return true;
    }
    else if(esp8266Module.find("NO CHANGE")){
      if(DEBUG){
        Serial.println("Already in mode 1");
      }  
      return true;
    }
    else
    {
      if(DEBUG){
        Serial.println("Error while changing mode");
      }  
      return false;
    }
}
