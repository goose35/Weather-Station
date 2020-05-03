//------------------------------------------------------------------------------------------------------------
/////////////////////////////////Rain Interrrupt handler routine//////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------
// Interrupt handler routine that is triggered when the rain sensor detects rain 
void isr_rg() {

  if((millis() - contactTime) > 15 ) { // debounce of sensor signal 
    tipCount1h++;
    tipCount24h++;
    contactTime = millis(); 
  } 
} 
