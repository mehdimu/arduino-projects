/*
    A complete OS with GO schedule display and current weather.
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  //set-up the serial connection
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {

  if (firstTime == 0){
      lcd.setCursor(0, 0);
      lcd.print("T: ");
      firstTime = 1;
    }

  if (Serial.available() > 0)  {
    data = Serial.read();
    if (data == 'W') {
      //new weather update
      data = Serial.read();
      lcd.setCursor(0, 3);
      while (data != -1) {
        lcd.print(data)
      }
    }

    if (data == 'S') {
      // new bus/train schedule
      data = Serial.read();
      lcd.setCursor(0, 3);
      while (data != -1) {
        lcd.print(data)
      }
    }


  value = Serial.read();
  lcd.print(value);
  }
  else {
    firstTime = 0;
  }
  delay(1000);
}
