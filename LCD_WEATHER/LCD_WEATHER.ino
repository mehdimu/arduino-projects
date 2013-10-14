/*
    A weather report.
 */

// include the library code:
#include <LiquidCrystal.h>
#include <iostream>
#include <string>

using namespace std;

// initialize the library with the numbers of the interface pins
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

char value;
int digitOne;
int digitTwo;
int firstTime;

void setup() {
    // set up the LCD's number of columns and rows:
    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop(){
  if (Serial.available())  {
    if (firstTime == 0){
      lcd.clear();
      lcd.print("Curr. Temp: ");
      firstTime = 1;
    }
     value = Serial.read();
     lcd.print(value);
  }
  else {
    firstTime = 0;
  }
  delay(1000);
}
