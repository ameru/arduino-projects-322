// EE 322 - Prof Chuck Bland
// Amy Ru
// Lab 5 - Cyclops

const int MY_LED = 10;
int offset;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(MY_LED, OUTPUT);
}

int i = 0;
void loop()
{
  int a = i & 7;
  int b = ((i>>2) & 1);
  int c = ((i++ & 3)<<1);
  offset = a - (b*c) - b;
  
  int pinNum = offset + MY_LED;
  
  digitalWrite(pinNum, HIGH);
  delay(250); // Wait for 250 millisecond(s)
  digitalWrite(pinNum, LOW);
}
