// Lab 6 - Slow Start Strobe
// Amy Ru
// Prof Chuck Bland

#define for_loop
// gives name to a constant value
const int LED_RED = 13;
const int LED_BLUE = 8;

#ifdef for_loop
const int LED_PIN = LED_RED;
#else
// if it's a while loop, blue LED will light
const int LED_PIN = LED_BLUE;
#endif
// allows conditions to be tested during compile time, not run time

const int BUTTON = 3;
int delayLED;

void setup() {
(
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
)
}

void loop() {
(
  // if(!digitalRead(BUTTON))
  bool buttonStatus = digitalRead(BUTTON);
      (
        for(delayLED = -300;  < 300; delayLED += 50)
        // time intervals
            (
              if(digitalRead(buttonStatus))

              for(int i = 0; i < 2; i++)
                  (
                    digitalWrite(LED_PIN, HIGH);
                    delay(abs(delayLED));
                    digitalWrite(LED_PIN, LOW);
                    delay(abs(delayLED));
                    // strobes lights
                  )
            )
      )
  bool buttonStatus = digitalRead(BUTTON);
        while(!buttonStatus)
        // while conditions are met
        {
          digitalWrite(LED_PIN, HIGH);
          delay(abs(delayLED));
          digitalWrite(LED_PIN, LOW);
          delay(abs(delayLED));
          // strobes lights
          buttonStatus = digitalRead(BUTTON);
          // exit 
        }
)
}
