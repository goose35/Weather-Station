//-------------------------------------------------------------------------------------------------------------
////////////////////////////////////ISR rotation//////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------------
// This is the function that the interrupt calls to increment the rotation count
void isr_rotation(void)   
{
  if ((millis() - ContactBounceTime) > 15 ) {  // debounce the switch contact.
    Rotations++;
    ContactBounceTime = millis();
  }
}
// Convert MPH to Knots
float getKnots(float speed) {
   return speed * 0.868976;          //knots 0.868976;
}
// Convert MPH to m/s
float getms(float speed) {
   return speed * 0.44704;           //metric m/s 0.44704;;
}
