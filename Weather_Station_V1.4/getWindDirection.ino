//-------------------------------------------------------------------------------------------------------------
/////////////////////////////////// Get Wind direction ////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------------
void getWindDirection(void) 
{
   VaneValue = analogRead(WindVanePin);
   Direction = map(VaneValue, 0, 1023, 0, 360);
   CalDirection = Direction + VaneOffset;
   
   if(CalDirection > 360)
     CalDirection = CalDirection - 360;
     
   if(CalDirection < 0)
     CalDirection = CalDirection + 360;
}

// Converts compass direction to heading
void getHeading(int direction) {
    if(direction < 22)
      Serial.print("N");
    else if (direction < 67)
      Serial.print(" NE");
    else if (direction < 112)
      Serial.print("E");
    else if (direction < 157)
      Serial.print(" SE");
    else if (direction < 202)
      Serial.print(" S");
    else if (direction < 247)
      Serial.print(" SW");
    else if (direction < 292)
      Serial.print(" W");
    else if (direction < 337)
      Serial.print(" NW");
    else
      Serial.print(" N");  
}

// converts wind speed to wind strength
void getWindStrength(float speed)
{
  if(speed < 1)
    Serial.println("Calm");
  else if(speed >= 1 && speed < 3)
    Serial.println("Light Air");
  else if(speed >= 3 && speed < 7)
    Serial.println("Light Breeze");
  else if(speed >= 7 && speed < 12)
    Serial.println("Gentle Breeze");
  else if(speed >= 12 && speed < 18)
    Serial.println("Moderate Breeze");
  else if(speed >= 18 && speed < 24)
    Serial.println("Fresh Breeze");
  else if(speed >= 24 && speed < 31)
    Serial.println("Strong Breeze");
  else if(speed >= 31 && speed < 38)
    Serial.println("High wind");
  else if(speed >= 38 && speed < 46)
    Serial.println("Fresh Gale");
  else if(speed >= 46 && speed < 54)
    Serial.println("Strong Gale");
  else if(speed >= 54 && speed < 63)
    Serial.println("Storm");
  else if(speed >= 63 && speed < 72)
    Serial.println("Violent storm"); 
  else if(speed >= 72 && speed)
    Serial.println("Hurricane");    
}
