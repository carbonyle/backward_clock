/*********************

Colored clock for the Adafruit RGB Character LCD Shield + SD-RTC shield

**********************/

#include <Wire.h>
#include "RTClib.h"
#include <utility/Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
RTC_DS1307 rtc;
DateTime now;

void setup()
{
  lcd.begin(16,2);
  Wire.begin();
  rtc.begin();
}

void loop() 
{
  now = rtc.now();
  updateTime();
}

void updateTime()
{

 // Time variables
 int s = now.second(); 
 int m = now.minute(); 
 int h = now.hour();
 int d = now.day();  
 int M = now.month();
 int y = now.year(); 
 
 // Clock
 lcd.setCursor(0,1);
 if (abs(h-12)<10) {lcd.print(0);} lcd.print(abs(h-12));
 lcd.print(":");
 if (abs(m-60)<10) {lcd.print(0);} lcd.print(abs(m-60));
 lcd.print(":");
 if (abs(s-60)<10) {lcd.print(0);} lcd.print(abs(s-60));

 // Calendar
 lcd.setCursor(0,0);
 if (d<10) {lcd.print(0);} lcd.print(d);
 lcd.print("/");
 if (M<10) {lcd.print(0);} lcd.print(M);
 lcd.print("/");
 lcd.print(y-2000);

}
