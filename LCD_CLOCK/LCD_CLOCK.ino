/*
    A working clock that resets when the plug is turned off.
 */
 
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int hour = 00;
int minute = 00;
int second = 00;

void setup() {
    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Amazing Clock!");
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    //  second = millis()/1000;
    delay(1000);
    second += 1;
    if (second == 60) {
        minute += 1;
        second = 0;
        if (minute == 60) {
            hour += 1;
            minute = 0;
            //second = 0;
            if (hour == 24) {
                hour = 0;
                //minute = 0;
                //second = 0;
            }
        }
    }
          
    lcd.setCursor(0, 1);
    if (hour >= 10) {    
        lcd.print(hour);
    }
    else {
        lcd.print("0");
        lcd.setCursor(1,1);
        lcd.print(hour);
    }

    lcd.setCursor(2,1);
    lcd.print(":");

    lcd.setCursor(3,1);
    if (minute >= 10) {    
        lcd.print(minute);
    }
    else {
        lcd.print("0");
        lcd.setCursor(4,1);
        lcd.print(minute);
    }

    lcd.setCursor(5,1);
    lcd.print(":");

    lcd.setCursor(6,1);
    if (second >= 10) {    
        lcd.print(second);
    }
    else {
        lcd.print("0");
        lcd.setCursor(7,1);
        lcd.print(second);
    }
}

