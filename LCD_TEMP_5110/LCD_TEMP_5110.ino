// LCD5110_ViewFont (C)2013 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the included full font.
//
// This program requires a Nokia 5110 LCD module
// and Arduino 1.5.2 (or higher).
//
// It is assumed that the LCD module is connected to
// the following pins.
//      SCK  - Pin 8
//      MOSI - Pin 9
//      DC   - Pin 10
//      RST  - Pin 11
//      CS   - Pin 12
//

#include <LCD5110_Basic.h>
#include <DS1302.h>

#include <dht11.h>

dht11 DHT11;

#define DHT11PIN 4

// Init the DS1302
DS1302 rtc(5, 6, 7);

LCD5110 myGLCD(8,9,10,11,12);

extern uint8_t SmallFont[];

void setup()
{
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  //myGLCD.invert(true);
  //myGLCD.invertText(true);  
//  rtc.setDOW(SATURDAY);        // Set Day-of-Week to FRIDAY
//  rtc.setTime(22, 22, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(7, 12, 2013);   // Set the date to August 6th, 2010

}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  
  myGLCD.clrScr();
  myGLCD.print("TIME: ", LEFT, 0);
  myGLCD.print(rtc.getTimeStr(), CENTER, 8);
  myGLCD.print(rtc.getDOWStr(), CENTER, 16);
  myGLCD.print(rtc.getDateStr(), CENTER, 24);
  myGLCD.print("TEMP: ", LEFT, 32);
  myGLCD.print((String)DHT11.temperature, CENTER, 40);
  delay(1000);
//  myGLCD.print("ABCDEFGHIJKLM", CENTER, 16);
//  myGLCD.print("NOPQRSTUVWXYZ", CENTER, 24);
//  delay (5000);
//  
//  myGLCD.clrScr();
//  myGLCD.print("Lower case:", LEFT, 0);
//  myGLCD.print("abcdefghijklm", CENTER, 16);
//  myGLCD.print("nopqrstuvwxyz", CENTER, 24);
//  delay (5000);
//  
//  myGLCD.clrScr();
//  myGLCD.print("Numbers:", LEFT, 0);
//  myGLCD.print("0123456789", CENTER, 16);
//  delay (5000);
//  
//  myGLCD.clrScr();
//  myGLCD.print("Special:", LEFT, 0);
//  myGLCD.print("!\"#$%&'()*+,-.", CENTER, 16);
//  myGLCD.print("/:;<=>?@[\\]^_`", CENTER, 24);
//  myGLCD.print("{|}~", CENTER, 32);
//  delay (5000);
}
