#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 1);
unsigned long duration;

int wsi =10;
float speedo=0;

void setup() {
Serial.begin (9600);
 pinMode(wsi, INPUT);
  pinMode(9, OUTPUT);
  lcd.begin(16, 2);
  tone(9, 320);
}
void loop() {

duration = pulseIn(wsi, HIGH);

lcd.setCursor(1, 1);
lcd.print(duration);
  /*
int nop=0;
float speedo=0;
int lc=0;
int starttime=millis();
int endtime = starttime;
lcd.setCursor(0, 0);
lcd.print(millis());
while (endtime-starttime <=1000) // do this loop for up to 1000mS
{
int readwsi = digitalRead( wsi );
if (readwsi==HIGH)
{
  nop=nop+1;
}
lc = lc+1;
endtime = millis();                             
}

lcd.setCursor(9, 1);
lcd.print(nop);

lcd.setCursor(0, 1);
lcd.print(loopcount);
Serial.print(loopcount,DEC);
 */
speedo = (159.5929*36)/(84*duration);

lcd.setCursor(1, 0);
lcd.print(speedo);

delay(1);
}
