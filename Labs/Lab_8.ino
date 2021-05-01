// Lab 08 - Breathing LED
// EE 322 Amy Ru
// Prof Chuck Bland

/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.
  
*/

int led = 9;              // the PWM pin the LED is attached to
int brightness = 0;       // how bright the LED is
int fadeAmount = 5;       // how many points to fade the LED by
const int PWM = 9;        // naming pin 9 as 'PWM' variable
const int ADC_PIN = A0;    // naming pin 0 of analog input side as analog-to-digital converter
 
// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(PWM,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  void FadeLED(int LEDPIN, int LEDSpeed);
    analogWrite(led, brightness);
    // set the brightness of pin 9:
    brightness = brightness + fadeAmount;
    // change the brightness for next time through the loop:
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    // reverse the direction of the fading at the ends of the fade:
    delay(30);
    // wait for 30 milliseconds to see the dimming effect
  int ReadAndMapPot(int AnalogInput);
  int adcReading = analogRead(ADC_PIN);
  // read the analog voltage and storing it in an integer
  
  for (int i = 0; i <= 255; i++); {
  adcReading = map(adcReading, 0, 255, 0, 1023);
  // sets acceptable values in range 0 to 255
  analogWrite(PWM. adcReading);
  // write the value to output port to generate PWM
  }
 }
