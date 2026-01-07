/* replace ? and add code in ???*/
#include "pitches.h"
#include "Arduino.h"
#include "NewPing.h"

// define ultrasonic pins
#define TRIG_PIN   ?       
#define ECHO_PIN    ?     

// define buzzer pin ？
#define BUZZER_PIN  ？   

//Define Built-in LED pin
#define LED_PIN ？      

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

//*** Define distance as a variable ***
float distance;  

//jingle bells high_tone

int melody_high[] = {
  
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_G4
};

int noteDurations_high[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8, 2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};
  //jingle bells LOW
int melody_low[] = {

  NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_E3, NOTE_G3, NOTE_C3, NOTE_D3, NOTE_E3,
  NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
  NOTE_F3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_E3, NOTE_D3, NOTE_D3, NOTE_E3,
  NOTE_D3, NOTE_G3
};

int noteDurations_low[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8, 2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};


void setup() {

  // initialize serial monitor
     ???
 // set pins mode
    ???
 
  
}

void loop() { 
  // Get the distance from the Ultrasonic Sensor
    float distance = sonar.ping_cm();
  
      if (distance > 10 ) {
        // turn on built in LED
        ???
      } else if (distance <= 10 && distance >= 5) {
        // turn off built in LED
        ???
        // play high tone Jingle-Bells Iterate over the notes of the melody_high:
        ???
      } else if (distance <5 ) {
        // turn off built in LED
        ???
        // play low tone Jingle-Bells Iterate over the notes of the melody_low
        ???
   
} 
  delay(?);
}
