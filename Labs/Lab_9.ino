// Lab 09 - Hello World
// EE 322 - Amy Ru
// Prof Chuck Bland

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
  {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.noDisplay(); // turn off the display
  delay(500);
  lcd.display(); // turn on the display
  lcd.setCursor(1, 0); // sets cursor at column 1, line 0
  lcd.print("Hello, World!!"); // print "Hello World" on first line 
  lcd.setCursor(0, 1); // sets cursor at column 0, line 1
  lcd.print("16X2 LCD Screen"); // print "16X2 LCD Screen" on second line
  }

void loop() 
  {
  // empty for now

  }
