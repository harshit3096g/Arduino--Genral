#include <LiquidCrystal.h>
 LiquidCrystal lcd(12, 11, 5, 4, 3, 10);
float start, finished;
float elapsed, time;
float circ=1.595929; // wheel circumference in meters
float speeed;
int j=0;
void setup()
{
  attachInterrupt(digitalPinToInterrupt(2), speedo, RISING); 
  start=millis();
  Serial.begin(115200);
    lcd.begin(16, 2);
    tone(9, 500);
 pinMode(0, INPUT_PULLUP);
 pinMode(8, INPUT_PULLUP);
 pinMode(6, INPUT_PULLUP);
 pinMode(7, INPUT_PULLUP);
                                  
}
void speedo()
{
  j++;
  elapsed=millis()-start;
  start=millis();
  speeed=(3600*circ)/(42*elapsed);
 } 
void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SPEED:");
  lcd.print(int(speeed));
  lcd.print("km/h");
  
   lcd.setCursor(0, 1);
     lcd.print("GEAR:");
if (digitalRead(0) == LOW)
{
 lcd.print("1");
}
else if (digitalRead(8) ==LOW)
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
lcd.setCursor(12,1);
lcd.print((0.0015959*(j-1))/42);
   lcd.setCursor(7,1);
   lcd.print("Dist:");
 delay(300); 
}
