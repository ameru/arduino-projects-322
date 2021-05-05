// Lab 7 - Ultrasonic Sensor
// Amy Ru
// EE 322 - Prof Chuck Bland


// constants need to be in UPPERCASE
// use "courier" font for better readiability and clean code!!

#include <HCSR04.h>

// initialize trig pins and leds
const int TRIGGERPIN = 13;
const int ECHOPIN = 12;
const int REDLED = 8;
const int GREENLED = 6; 
const int BLUELED = 5;
const int BUZZER = 3;

UltraSonicDistanceSensor distanceSensor(TRIGGERPIN, ECHOPIN);
// this is a type, not a variable name

void setup () 
    {
    Serial.begin(9600); // initialize baud rate at 9600
    pinMode(REDLED, OUTPUT); 
    pinMode(GREENLED, OUTPUT);
    pinMode(BLUELED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    }

void loop () 
    {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters
    double distance = distanceSensor.measureDistanceCm();

      if (distance == -1) // if out of range, no lights
        {
        digitalWrite(REDLED, LOW);
        digitalWrite(GREENLED, LOW);
        digitalWrite(BLUELED, LOW);
        }
        
      else if (distance <= 75) // if distance is less than 75 cm, red light on
        {
        digitalWrite(REDLED, HIGH);
        digitalWrite(GREENLED, LOW);
        digitalWrite(BLUELED, LOW);

        makeNoise(distance);
        }
        
      else if (distance > 75 && distance < 150) // if distance is between 75 and 150 cm, green light on
        {
        digitalWrite(REDLED, LOW);
        digitalWrite(GREENLED, HIGH);
        digitalWrite(BLUELED, LOW);

        makeNoise(distance);
        }
        
      else // all other scenarios (> 150 cm), blue light on
        {
        digitalWrite(REDLED, LOW);
        digitalWrite(GREENLED, LOW);
        digitalWrite(BLUELED, HIGH);

        makeNoise(distance);
        }

      Serial.print(distance);
    }


void makeNoise(double timeDelay) // cast variable timeDelay as a double
  {
  digitalWrite(BUZZER, HIGH); // sound ON
  delay((int)timeDelay);
  digitalWrite(BUZZER, LOW); // sound OFF
  delay((int)timeDelay);
  }
