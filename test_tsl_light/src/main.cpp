#include <Arduino.h>
#include "test_tsl.h"
#include "mydht.h"
#include "RFcontrol.h"
#include "ultrasonic.h"
#include "io_connect.h"

int loopslice = 0;
bool isClose = true;
 

void setup(void) 
{
  Serial.begin(115200);
 
  Serial.println("Starting Adafruit TSL2591 Test!");

  init_usonic();

  initial_RF();// init for remote control sokcet

  dht_init();
 
  printMessage();
 
  /* Configure the sensor */
  configureSensor();

  connection_setup();
}

void detect_distance(){
  int dis = measure_usonic();
  if(dis<200 && isClose){
    tonSig2();
    
  }else if(dis<200 && !isClose){
    toffSig2();
  }
}
 
void loop(void) 
{ 
  simpleRead(); //220 to open the light
  //advancedRead();
  // unifiedSensorAPIRead();

  printDHT();

  measure_usonic();

  connection_loop();

  if(++loopslice==50){
    mqtt_send_temphum();
    loopslice=0;
  }
  delay(500);
}