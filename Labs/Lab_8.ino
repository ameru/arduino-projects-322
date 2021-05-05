// Lab 08 - Breathing LED
// EE 322 Amy Ru
// Prof Chuck Bland

const int LEDPIN = 9; // naming pin 9 as PWM variable
const int POT_PIN = A0; // naming pin 0 as analog input
const int MIN_ADC = 0; // setting min adc range
const int MAX_ADC = 255; // setting max adc range

void setup()  
   { 
   pinMode(LEDPIN, OUTPUT); // set 9 as output pin for led
   Serial.begin(9600); // set serial begin rate at 9600 milliseconds
   } 

void loop()  
   {
    int potSpeed = ReadAndMapPot(POT_PIN); // read potentiometer speed
    
    Serial.println(potSpeed); // print speed setting

    BrightnessUp(potSpeed); // going from zero to full brightness
    BrightnessDown(potSpeed); // going from full to zero brightness
    FadeLED(LEDPIN, potSpeed); // make a call to fade function
   }
                 
int ReadAndMapPot(int AnalogInput)
  {
    int adcReading = analogRead(AnalogInput); // storing analog value in "adcReading" as integer
    adcReading = map(adcReading, 0, 1023, MIN_ADC, MAX_ADC); // map to range of 0-1023
    return(adcReading);
  }

void BrightnessUp(int speed)
  {
  for (int i = 0; i <= 255; i++) // incrementing upwards from 0 to 255
    {
    analogWrite(LEDPIN, i);
    delay(speed);
    }
  }

void BrightnessDown(int speed)
  {
  for (int i = 255; i >= 0; i--) // incrementing downwards from 255 to 0
    {
     analogWrite(LEDPIN, i);
     delay(speed);
    }    
  }

void FadeLED(int LEDPIN, int LEDSpeed) // function to fade brightness of LED based on speed

   {
    BrightnessUp(LEDPIN); // brightness output to LEDPIN
    delay(int(LEDSpeed)); // delay time based on LED speed
    BrightnessDown(LEDPIN); // brightness output to LEDPIN
    delay(int(LEDSpeed)); // delay time based on LED speed
   }
