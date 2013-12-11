
#include <LiquidCrystal.h>

//set up the display drivers/library
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

char data;
int count;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("T: ");

  lcd.setCursor(7, 0);
  lcd.print("F: ");

  lcd.setCursor(0, 1);
  lcd.print("GO: ");
}


void loop() {
  data = Serial.read();

  if (data == -1) {
    //do nothing, if no data is detected
    ;
  }

  else {
    //data coming in

    //wait for all the data to transfer into buffer
    delay(5000);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("T: ");

    lcd.setCursor(7, 0);
    lcd.print("F: ");

    lcd.setCursor(0, 1);
    lcd.print("GO: ");

    //print the temperature
    lcd.setCursor(3, 0);
    while (data != '/') {
      lcd.print(data);
      data = Serial.read();
    }

    data = Serial.read();

    //print the "feels like"
    lcd.setCursor(10, 0);
    while (data != '_') {
      lcd.print(data);
      data = Serial.read();
    }

    data = Serial.read();

    //print milton departure time
    lcd.setCursor(4, 1);
    while (data != '/') {
      lcd.print(data);
      data = Serial.read();
    }

    data = Serial.read();

    //print the union departure time
    lcd.setCursor(11, 1);
    while (data != -1) {
      lcd.print(data);
      data = Serial.read();
    }
  }
}



