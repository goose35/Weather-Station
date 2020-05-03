//------------------------------------------------------------------------------------------------------------
///////////////////////////////////Send data to Thingspeak////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------

void updateData(float tempc, float baromhpa, float humidity, float uvIntensity, float dewptf,  float windSpeed,  int Direction,  float rain24h){ 
  
  if(counter == UpdateInterval){
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  esp8266Module.println(cmd);
  delay(5000);
  if(esp8266Module.find("Error")){
    if(DEBUG){
      Serial.println("ERROR while SENDING");
    }  
    return;
  }
  
  cmd = GET +   "&field1=" + tempc +   "&field2=" + baromhpa +   "&field3=" + humidity +   "&field4=" + uvIntensity +  "&field5=" + dewptf +   "&field6=" + windSpeed +   "&field7=" + Direction +   "&field8=" + rain24h + "\r\n";
  digitalWrite(GREEN_LED,HIGH);  // Green led is turn on then sending data
  esp8266Module.print("AT+CIPSEND=");
  esp8266Module.println(cmd.length());
  delay(15000);
  if(esp8266Module.find(">"))
  {
    esp8266Module.print(cmd);
        if(DEBUG){
      Serial.println("Data send");
    }
    delay(1000);
    
  }else
  {
    esp8266Module.println("AT+CIPCLOSE");
    if(DEBUG){
      Serial.println("Connection closed");
    }  
  }
  digitalWrite(GREEN_LED,LOW);
  }
    delay(2500);
  Counter();
}
