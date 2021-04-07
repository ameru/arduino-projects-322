/* Sketch 1
 *  Blink an LED connected to digital pin 5
 *  Off time is 1 second
 *  On time is .25 second
 */

void setup() {
  pinMode(5, OUTPUT)
}

void loop() {
  // pif you place this code in the loop before the loop, the LED will only run once
  digitalWrite(5, LOW);
  delay(1000);
  digitalWrite(5, HIGH);
  delay(250);
}

/* Sketch 2
 * Read a button connected between digital pin 2 and ground
 *  Turn on the internal LED only when the button is pushed
 */

const int MY_BUTTON = 2;
const int MY_LED = 13; // I could've used LED_BUILTIN

void setup() {
  pinMode(MY_BUTTON, INPUT_PULLUP);
  pinMode(MY_LED, OUTPUT);
}

void loop() {
  int buttonRead;
  buttonRead = digitalRead(MY_BUTTON);
  if (buttonRead)
    {
     // button is pushed
     // turn LED on
     digitalWrite(MY_LED, HIGH);
    }
  else
    {
      // button is not pushed
      // turn LED off
      digitalWrite(MY_LED, LOW);
    }
    }
