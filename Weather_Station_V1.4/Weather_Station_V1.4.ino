//Weather Station v1.4 Mod: S.Orton 11-01-2020
//Added UpdateInterval variable to set upload frequency
//Added if (counter == UpdateInterval) to counter function to vary upload frequency

#include <LowPower.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <math.h>
#include "TimerOne.h"
#include <OneWire.h>
#include <stdlib.h>

#define Bucket_Size 0.02           // rain bucket size inches  ( 0.5mm)
#define GREEN_LED 13               //tx led
#define SEALEVELPRESSURE_HPA (1013.25)
#define WindSensorPin (3)          // The pin anemometer sensor is connected to
#define WindVanePin (A0)           // The pin the wind vane sensor is connected to
#define VaneOffset 0;              // Sensor offset from north 0-360
Adafruit_BME280 bme ;              // I2C  BME280 sensor
#define BME280_ADDRESS (0x76)      // SDO conect to GND address 0x76 or  CSB +3.3V address 0x77  
#define RainSensorPin 2            // The pin rain sensor is connected to
#define ONE_WIRE_BUS 4             // The pin temperature  DS18B20 sensor
#define DEBUG 0

volatile unsigned long tipCount1h;     // bucket tip counter used in interrupt routine
volatile unsigned long tipCount24h;    // bucket tip counter used in interrupt routine  
volatile unsigned long contactTime;    // Timer to manage any contact bounce in interrupt routine

volatile bool IsSampleRequired;       // this is set true every 2.5s. Get wind speed
volatile unsigned int  TimerCount;    // used to determine 2.5sec timer count for sampling
volatile unsigned long Rotations;     // cup rotation counter used in interrupt routine
volatile unsigned long ContactBounceTime;  // Timer to avoid contact bounce in interrupt routine

SoftwareSerial esp8266Module(10, 11); // RX, TX ESP8266
int UVOUT = A2; //Output from the sensor  UV Sensor
int REF_3V3 = A3; //3.3V power on the Arduino board UV Sensor
unsigned long delayTime;

int VaneValue;           // raw analog value from wind vane
int Direction;           // translated 0 - 360 direction
int CalDirection;        // converted value with offset applied
int LastValue;
float tempc;             // Temp celsius  BMP280
float tempc_min= 100;    // Minimum temperature C
float tempc_max;         // Maximum temperature C
float humidity;          // Humidity BMP280
float tempf=0;           // Temp farenheit BMP280
float dewptf=0;          // dew point tempc
float barompa;           // Preasure pascal Pa
float baromin;           // Preasure inches of mercury InHg
float baromhpa;          // Preasure hectopascal hPa
float refLevel;
float uvLevel;
float outputVoltage;
float uvIntensity = 0;   // UV 
float UVmax = 0;         // maximum UV intensity over the past 10 minutes
float altitudepws = 75.00;  //Local  altitude of the PWS to get relative pressure  meters (m)
float windSpeed;         // Wind speed (mph)
float wind_min = 100;     // Minimum wind speed (mph)
float wind_avg;          // 10 minutes average wind speed ( mph)
float windgustmph = 0;   // Maximum Wind gust speed( mph)
float rain1h = 0;        // Rain inches over the past hour
float rain24h = 0;       // Rain inches over the past 24 hours

unsigned int counter = 0;
unsigned int UpdateInterval = 10; //update data interval
unsigned int raincount1h = 0;
unsigned int raincount24h = 0;

//------------------------------------------------------------------------------------------------------------
//////////////////////////////////////////Network Details/////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------

String network = "VM4726600"; // your access point SSID
String password = "j7rRsHzwdpmb"; // your wifi Access Point password

#define IP "184.106.153.149" //thingspeak IP
String GET = "GET /update?key=A31I8HNRREF8X44G"; // API Key
/*
char server [] = "rtupdate.wunderground.com";        
char WEBPAGE [] = "GET /weatherstation/updateweatherstation.php?";
char ID [] = "IRUGEL1";        //wunderground weather station ID            
String PASSWORD  = "fBzDvfob";   // wunderground weather station password
*/
//------------------------------------------------------------------------------------------------------------
///////////////////////////////////////////////Main Program///////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------

void setup() {
//set the clock prescaler
//CLKPR = 0x80;
//CLKPR = 0x02;

//esp8266Module.println(F("AT+SLEEP=1"));set esp 8266 sleep mode to light sleep

LastValue = 0;
IsSampleRequired = false;
TimerCount = 0;  // set TimerCount to 0 for interupts
tipCount1h = 0;
tipCount24h = 0;
{

Serial.begin(9600);
esp8266Module.begin(115200);
esp8266Module.println("AT+RST");
pinMode(UVOUT, INPUT);
pinMode(REF_3V3, INPUT);
pinMode(GREEN_LED,OUTPUT);
pinMode(RainSensorPin, INPUT);
pinMode(WindSensorPin, INPUT);
bme.begin(0x76);
Wire.begin();
delay(1000);
}

attachInterrupt(digitalPinToInterrupt(WindSensorPin), isr_rotation, FALLING); // Setup the wind timer intterupt
attachInterrupt(digitalPinToInterrupt(RainSensorPin), isr_rg, FALLING); // Setup the rain timer intterupt
Timer1.initialize(500000); // Timer interrupt every 0.5 seconds
Timer1.attachInterrupt(isr_timer);
sei();// Enable Interrupts
Serial.println("Start LovettSTN");
delay(3000);

}
  
void loop() {
read_data();    // read different sensors data from analog and digital pins of arduino
getWindSpeed();
isr_timer();
isr_rotation();
getRain();
getWindDirection();
updateData( float(tempc),  float(baromhpa),  float(humidity),  float(uvIntensity),  float(dewptf),  float(windSpeed),  int(Direction),  float(rain24h)); // sends data to thingspeak
if(DEBUG){
print_data();   // print in serial monitor
}
setupEsp8266();   //reset and connect esp
//LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);//(sleep arduino for 8 seconds

}
