#include <SPI.h>
//#include <openGLCD.h>
#include<LiquidCrystal.h>
unsigned long start, finished, lapTime;
boolean r = false;
boolean z = false;
long lastPressTime = 0; 
long lastPressTime1 = 0; 
long deelay = 200; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
 //GLCD.Init();
  lcd.begin(16, 2);

Serial.begin(9600);

  //GLCD.SelectFont(System5x7);
  //GLCD.print("Initialising");
  lcd.print("Initialising");
  Serial.println("Initialising");
  delay(1000); 
 //GLCD.ClearScreen();
 lcd.clear();
 //GLCD.CursorTo(1, 4);
 //GLCD.print("READY");
 lcd.print("READY");
  
 Serial.println("READY");
 pinMode(8,OUTPUT);
 digitalWrite(8,LOW);
pinMode(9,OUTPUT);
 digitalWrite(9,HIGH);
 pinMode(7,OUTPUT);
 digitalWrite(7,HIGH);
}

void loop()
{
CheckStart();
CheckStop();
DisplayResult();
delay(50);
}

void CheckStart()
{
int x = analogRead (5);

if (x < 200 && r==false) 
{
    if ((millis() - lastPressTime) > deelay)
    {  
          //GLCD.ClearScreen();
          //GLCD.CursorTo(2, 4); 
          //GLCD.print("Time Past");
          lcd.clear();
          lcd.setCursor(1,1);
          lcd.print(" Time Past");
          Serial.println("Time Past");
          start = millis();
          z=true;  
          r=true;
    }
lastPressTime = millis();
}
}
void CheckStop()
{
 int y = analogRead (4);

 if(z==true)
 {
 if (y < 200)
  {
    if ((millis() - lastPressTime1) > deelay)
      {  
          //GLCD.CursorTo(1, 4); 
          //GLCD.print(" Final Time ");
          lcd.setCursor(1,1);
          lcd.print("Final Time");
          Serial.println("Final Time");
          r=false;       
      }
    lastPressTime1 = millis(); 
  }
 }
}
void DisplayResult()
{
if (r == true)
{
finished = millis();

float m, s, ms;
unsigned long over;

lapTime = finished - start;

over = lapTime % 3600000;
m = int(over / 60000);
over = over % 60000;
s = int(over / 1000);
ms = over % 1000;

//GLCD.CursorTo(6, 1);
lcd.setCursor(1,0);
lcd.print(m,0);
//GLCD.print(m, 0);
Serial.print(m, 0);

lcd.print("m ");
//GLCD.print("m ");
Serial.print("m ");

lcd.print(s,0);
//GLCD.print(s, 0);
Serial.print(s, 0);

lcd.print("s ");
//GLCD.print("s ");
Serial.print("s ");

lcd.print(ms,0);
//GLCD.print(ms, 0);
Serial.print(ms, 0);

lcd.print("ms ");
//GLCD.print("ms ");
Serial.print("ms ");
Serial.println("");
}
}
