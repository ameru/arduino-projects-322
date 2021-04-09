// EE322 - Prof Chuck Bland
// Amy Ru
// Lab 4

// declare all pins and variables const int RED_LED = 13;
const int GRN_LED = 12; const int BLU_LED = 11;
const int BUTTON = 10;
void setup() {
pinMode(RED_LED, OUTPUT); pinMode(GRN_LED, OUTPUT); pinMode(BLU_LED, OUTPUT); pinMode(BUTTON, INPUT_PULLUP); }
void loop() {
if (digitalRead(BUTTON)==LOW) {
digitalWrite(RED_LED, HIGH);
delay(1000); // Wait for 1000 millisecond(s) digitalWrite(RED_LED, LOW);
digitalWrite(GRN_LED, HIGH); delay(1000); // Wait for 1000 millisecond(s) digitalWrite(GRN_LED, LOW);
digitalWrite(BLU_LED, HIGH);
delay(1000); // Wait for 1000 millisecond(s) digitalWrite(BLU_LED, LOW);
}
}
// activates light sequence only when button is pushed
// red button lights up // wait one second
// green button lights up // wait one second
// blue button lights up //wait one second
