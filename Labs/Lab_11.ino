// Lab 11 - DHT
// EE 322 - Amy Ru
// Prof Chuck Bland

#include <SimpleDHT.h>

// Setup variables
const int DHT_PIN = 5;
const int SPEED_PIN = 11;
const int DIRECTION_1 = 12;
const int DIRECTION_2 = 13;

int tempF;
int lastTemp = -200;
SimpleDHT11 dht11(DHT_PIN);

void setup() 
  {
  // setup serial rate and pins
  Serial.begin(9600);
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(DIRECTION_1, OUTPUT);
  pinMode(DIRECTION_2, OUTPUT);
  }

void loop() 
  {
  byte temperature = 0; //set initial temp to 0
  byte humidity = 0; // set initial humidity to 0
  int err = SimpleDHTErrSuccess;
  
  // reporting error statement to serial monitor (from github example)
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
    {
    Serial.print("Read DHT11 failed, err="); 
    Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); 
    Serial.println(SimpleDHTErrDuration(err)); 
    delay(1000);
    return;
    }

  // convert to Fahrenheit
  tempF = (int)(((float)temperature * 1.8) + 32); 

  if (tempF != lastTemp)
  {
    lastTemp = tempF;
      Serial.print((int)tempF); Serial.print(" *F, ");
      Serial.print((int)humidity); Serial.print(" %H Motor: ");
      
  if(tempF < 75) // spin counterclockwise
    {
    digitalWrite(DIRECTION_1, HIGH); // turn on RED LED
    digitalWrite(DIRECTION_2, LOW);
    digitalWrite(SPEED_PIN, HIGH);
    Serial.println("Backward");
    }
   else if(tempF > 80) // spin clockwise
    {
    digitalWrite(DIRECTION_1, LOW);
    digitalWrite(DIRECTION_2, HIGH); // turn on GREEN LED
    digitalWrite(SPEED_PIN, HIGH);
    Serial.println("Forward");
    }
   else
    {
    digitalWrite(SPEED_PIN, LOW);
    Serial.println("Off");
    }
  }
  delay(2000);
  }
