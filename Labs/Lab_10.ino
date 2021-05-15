// Lab 10 - LCD Display
// EE 322
// Prof Chuck Bland

// Import Libraries
#include <LiquidCrystal.h>
#include <JC_Button.h>
// Associating LCD pins with arduino pin number they are connected to
const int RS_PIN = 12;
const int EN_PIN = 11;
const int D4_PIN = 5;
const int D5_PIN = 4;
const int D6_PIN = 3;
const int D7_PIN = 2;
LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
// Joystick constants and variables
const int X_PIN = A0;
const int Y_PIN = A1;
const int JOYSTICK_PIN = A2;
int x_Axis;
int y_Axis;
ToggleButton myToggle(JOYSTICK_PIN);
int JoystickValue;
void setup()
  {
    lcd.begin(16, 2); // set up the LCD's number of columns and rows
    lcd.noDisplay(); // turn off the display
    delay(1000); // delay for one second
 
lcd.display(); // turn on the display
    lcd.setCursor(0, 0); // sets cursor at column 0, line 0
    lcd.print("X-Axis:"); // print "X-Axis: " on first line
    lcd.setCursor(0, 1); // sets cursor at column 0, line 1
    lcd.print("Y-Axis:"); // print "Y-Axis: " on second line
    myToggle.begin(); // setup joystick toggle
}
void loop() {
    lcd.setCursor(8, 0); // reset first 8 digits of x-axis input
    x_Axis = analogRead(X_PIN);
    x_Axis = map(x_Axis, 0, 1023, -512, 512); // set cursor range from -512 to 512
    lcd.print(x_Axis);
    lcd.print("   "); // print 3 spaces after the number to avoid orphaned digits
    lcd.setCursor(8, 1); // reset first 8 digits of y-axis input
    y_Axis = analogRead(Y_PIN);
    y_Axis = map(x_Axis, 0, 1023, 512, -512); // set cursor range from -512 to 512
    lcd.print(y_Axis);
    lcd.print("   "); // print 3 spaces after the number to avoid orphaned digits
    myToggle.read(); // toggle LCD with joystick
    if (myToggle.changed())
    {
      // toggle LED Display off/on if joystick was released
      digitalWrite(A2, myToggle.toggleState()); // A2 connects to SW, output for pushbutton
    }
}
