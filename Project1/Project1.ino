#include "pitches.h"
#include "Arduino.h"
#include "NewPing.h"

// define ultrasonic pins
#define TRIG_PIN   6      
#define ECHO_PIN   5    

// define buzzer pin
#define BUZZER_PIN  35  

// Define Built-in LED pin
// Note: On many ESP32 boards, the built-in LED is GPIO 2.
// If GPIO 1 doesn't work, try changing this to 2.
#define LED_PIN 1      

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

//*** Define distance as a variable ***
float distance;  

// --- Jingle Bells High Tone Data ---
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

// --- Jingle Bells Low Tone Data ---
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

// Calculate the number of notes in the melody (both are same length)
int melodyLength = sizeof(melody_high) / sizeof(melody_high[0]);

void setup() {
  // initialize serial monitor
  Serial.begin(9600);
 
  // set pins mode
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Get the distance from the Ultrasonic Sensor
  // Note: NewPing returns 0 if distance is greater than MAX_DISTANCE
  distance = sonar.ping_cm();
 
  // Debugging: Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logic Flow based on Flowchart
 
  if (distance > 10 || distance == 0) {
    // turn on built in LED
    digitalWrite(LED_PIN, HIGH);
    noTone(BUZZER_PIN); // Ensure buzzer is silent
  }

  else if (distance <= 10 && distance >= 5) {
    // turn off built in LED
    digitalWrite(LED_PIN, LOW);
   
    // play high tone Jingle-Bells
    for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
      // Calculate note duration (1000 divided by note type, e.g., quarter note = 1000/4)
      int noteDuration = 1000 / noteDurations_high[thisNote];
      tone(BUZZER_PIN, melody_high[thisNote], noteDuration);

      // Pause between notes to distinguish them
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
     
      // Stop the tone before the next one
      noTone(BUZZER_PIN);
    }
  }
  // Condition 3: distance < 5cm
  else if (distance < 5 && distance > 0) {
    // turn off built in LED
    digitalWrite(LED_PIN, LOW);
   
    // play low tone Jingle-Bells
    for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
      int noteDuration = 1000 / noteDurations_low[thisNote];
      tone(BUZZER_PIN, melody_low[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
     
      noTone(BUZZER_PIN);
    }
  }
 
  // Small delay to stabilize sensor readings
  delay(100);
}