// include the library code:
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 10);
void setup() 
{
 pinMode(0, INPUT_PULLUP);
 pinMode(1, INPUT_PULLUP);
 pinMode(6, INPUT_PULLUP);
 pinMode(7, INPUT_PULLUP);
 
 lcd.begin(16, 2);
}
void loop() 
{
 lcd.setCursor(7, 1);
if (digitalRead(0) == LOW)
{
 lcd.print("1");
}
else if (digitalRead(1) ==LOW)
{
 lcd.print("2");
}
else if (digitalRead(6) ==LOW)
{
 lcd.print("3");
}
else if (digitalRead(7) ==LOW)
{
 lcd.print("4");
}
else
{
 lcd.print("0");
}
}
