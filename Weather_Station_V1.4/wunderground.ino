/*
//-------------------------------------------------------------------
// Following function sends sensor data to wunderground.com
//-------------------------------------------------------------------

void wunderground(void)
{
 String cmd1 = "AT+CIPSTART=\"TCP\",\"";
  cmd1 += "rtupdate.wunderground.com"; // wunderground
  cmd1 += "\",80";
  esp8266Module.println(cmd1);

  if(esp8266Module.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  String cmd = "GET /weatherstation/updateweatherstation.php?ID=";
  cmd += ID;
  cmd += "&PASSWORD=";
  cmd += PASSWORD;
  cmd += "&tempc=";
  cmd += tempc;
  cmd += "&humidity=";
  cmd += humidity;
  cmd += "&baromhpa=";
  cmd += baromhpa;
  cmd += "&uvIntensity=";
  cmd += uvIntensity;
  cmd += "&softwaretype=Arduino-ESP8266&action=updateraw&realtime=1&rtfreq=30";   // &softwaretype=Arduino%20UNO%20version1
  cmd += "/ HTTP/1.1\r\nHost: host:port\r\nConnection: close\r\n\r\n";

  cmd1 = "AT+CIPSEND=";
  cmd1 += String(cmd.length());
  esp8266Module.println(cmd1);
  if(esp8266Module.find(">")){
    esp8266Module.print(cmd);
    digitalWrite(GREEN_LED,HIGH);  // Green led is turn on then sending data to Wunderground
    Serial.println("Data send OK");
    delay(1000);
    digitalWrite(GREEN_LED,LOW);
      }
  else{
    esp8266Module.println("AT+CIPCLOSE");
    Serial.println("Connection closed");
    Serial.println(" ");  
  }
  delay(2500);
delay(2500); 
Counter();  
}

*/
