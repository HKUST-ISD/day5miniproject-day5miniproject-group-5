/* replace ? and add code in ???*/
#include <Arduino.h>
#include "pitches.h"
#include <DHT.h>
#include "NewPing.h"
#include <ESP32Servo.h>

// define DHT11 sensor pin
#define DHT_PIN   37
Servo servo;
#define DHT_TYPE DHT11
DHT dht11(DHT_PIN, DHT_TYPE);

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.


//define pins
#define LED_PIN 1
#define DHT_PIN   37
#define TRIG_PIN 6  
#define ECHO_PIN  5  
#define BUZZER_PIN 15
#define Servo_PIN 40
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
int melody[] = {
  NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_E3, NOTE_E3, NOTE_E3,
};

int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8
};
int melodylength= sizeof(melody)/sizeof(int);

void setup() {
  // Initialize Serial Monitor 
  Serial.begin(9600);    
  // initialize the DHT11 sensor
  dht11.begin();
  //attach servo pin
  servo.attach(Servo_PIN);
  // config the pin mode of each pin
  pinMode(DHT_PIN , INPUT);
  pinMode(TRIG_PIN, INPUT);
  pinMode(ECHO_PIN,INPUT);
  //pinMode(SERVO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  //
}

void loop() {
   float distance = sonar.ping_cm();
  // read humidity
  float humi  = dht11.readHumidity();
  // read temperature in Celsius
  float tempC = dht11.readTemperature();
  // read temperature in Fahrenheit
  float tempF = dht11.readTemperature(true);

  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else if (tempC <= 30) {
      
        // servo motor stop 
        servo.write(90);
       // Serial Monitor show Safe
        Serial.println("Safe");
       // buzzer no sound
        noTone(BUZZER_PIN);
  } else if (humi >= 30) {
       // servo motor stop 
        servo.write(90);
       // Serial Monitor show Caution
       Serial.println("Caution");
       // buzzer continuously alarm
        for (int note = 0; note < melodylength; note++) {
         int noteDuration = 1000 / noteDurations[note];
      tone(BUZZER_PIN, melody[note], noteDuration);
        }
       // report heat source distance from Ultrasonic sensor
        Serial.print("Heat of Distance: ");
     Serial.print(distance);
      Serial.println(" cm");
    } 
    else if (humi < 30)  {
      // servo motor run
        servo.write(180);
       // Serial Monitor show Dangerous
        Serial.println("Dangerous");
       // buzzer beep
       for (int note = 0; note < melodylength; note++) {
         int noteDuration = 500 / noteDurations[note];
      tone(BUZZER_PIN, melody[note], noteDuration);
        }
        //delay(20)
  }
  

  // wait a 2 seconds between readings
  delay(2000);
}
