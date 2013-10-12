/*
    A working clock that resets when the plug is turned off.
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

class SIMPLECLOCK {
    public:
    int hour;
    int minute;
    int second;
    void tick();
    void checkTime();
};

void SIMPLECLOCK::tick () {
    second += 1;
}

void SIMPLECLOCK::checkTime () {
    if (second == 60) {
        minute += 1;
        second = 0;
        if (minute == 60) {
            hour += 1;
            minute = 0;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}

SIMPLECLOCK simpleClock;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Ali's Clock!");
}

void loop() {

    delay(1000);
    simpleClock.tick();
    simpleClock.checkTime();
    lcd.setCursor(0, 1);
    if (simpleClock.hour >= 10) {
        lcd.print(simpleClock.hour);
    }
    else {
        lcd.print("0");
        lcd.setCursor(1,1);
        lcd.print(simpleClock.hour);
    }

    lcd.setCursor(2,1);
    lcd.print(":");

    lcd.setCursor(3,1);
    if (simpleClock.minute >= 10) {
        lcd.print(simpleClock.minute);
    }
    else {
        lcd.print("0");
        lcd.setCursor(4,1);
        lcd.print(simpleClock.minute);
    }

    lcd.setCursor(5,1);
    lcd.print(":");

    lcd.setCursor(6,1);
    if (simpleClock.second >= 10) {
        lcd.print(simpleClock.second);
    }
    else {
        lcd.print("0");
        lcd.setCursor(7,1);
        lcd.print(simpleClock.second);
    }
}

