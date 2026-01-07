/* replace ? and add code in ???*/
#include <Arduino.h>
#include <DHT.h>
#include "NewPing.h"
#include <ESP32Servo.h>

// define DHT11 sensor pin
#define DHT_PIN   ?

#define DHT_TYPE DHT11
DHT dht11(DHT_PIN, DHT_TYPE);

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

//define pins
#define LED_PIN ?
#define DHT_PIN   ?
#define TRIG_PIN ?        
#define ECHO_PIN  ?       
#define BUZZER_PIN ?     
#define Servo_PIN ? 



void setup() {
  // Initialize Serial Monitor 
  Serial.begin(?);    
  // initialize the DHT11 sensor
  dht11.begin();
  //attach servo pin
  servo.attach(?);
  // config the pin mode of each pin
  ???
  //
}

void loop() {

  // read humidity
  float humi  = dht11.readHumidity();
  // read temperature in Celsius
  float tempC = dht11.readTemperature();
  // read temperature in Fahrenheit
  float tempF = dht11.readTemperature(true);

  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else if (temp <= 30) {
      
        // servo motor stop 
        ???
       // Serial Monitor show Safe
        ???
       // buzzer no sound
        ???
  } else if (humi >= 30) {
       // servo motor stop 
        ???
       // Serial Monitor show Caution
        ???
       // buzzer continuously alarm
        ??? 
       // report heat source distance from Ultrasonic sensor
        ???
    } 
    else if (humi < 30)  {
      // servo motor run
        ???
       // Serial Monitor show Dangerous
        ???
       // buzzer beep
        ???
  }
  

  // wait a 2 seconds between readings
  delay(2000);
}
