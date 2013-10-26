
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

char data;
char flag = 'N';
int count;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Ali's Clock!");
  Serial.begin(9600);
  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("T: ");
//  //Temp
//  lcd.setCursor(3, 0);
//  lcd.print("+14");
//  lcd.setCursor(7, 0);
//  lcd.print("F: ");
//  //Feels like
//  lcd.setCursor(10, 0);
//  lcd.print("-14");
//  
//  lcd.setCursor(0, 1);
//  lcd.print("GO: ");
//  //Milton Time
//  lcd.setCursor(4, 1);
//  lcd.print("11:04");
//  lcd.setCursor(9, 1);
//  lcd.print("|");
//  //Union Time
//  lcd.setCursor(10, 1);
//  lcd.print("12:05");

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
      flag = 'N';  
    }
    
    else {
      delay(5000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("T: ");
      
      lcd.setCursor(7, 0);
      lcd.print("F: ");
      
      lcd.setCursor(0, 1);
      lcd.print("GO: ");
      
      lcd.setCursor(3, 0);
      while (data != '/') {      
        lcd.print(data);
        data = Serial.read();
      }
      
      data = Serial.read();
      lcd.setCursor(10, 0);
      while (data != '_') {
        lcd.print(data);
        data = Serial.read();
      }
      
      data = Serial.read();
      lcd.setCursor(4, 1);
      while (data != '/') {
        lcd.print(data);      
        data = Serial.read();
      }
      data = Serial.read();
      lcd.setCursor(11, 1);
      while (data != -1) {
        lcd.print(data);
        data = Serial.read();   
      }
    }
}



