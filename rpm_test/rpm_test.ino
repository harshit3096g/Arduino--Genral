#include <LiquidCrystal.h>
LiquidCrystal lcd(22,23,24,25,26,27);
#define input 21
/*
#define led1 22
#define led2 23
#define led3 24
#define led4 25
#define led5 26
#define led6 27
#define led7 28
#define led8 29
#define led9 30
#define led10 31
*/
 // to generate tone
unsigned long start_time;
unsigned int count;
unsigned long stop_time;
int RPM=0;

void setup() {
  Serial.begin(115200);
   lcd.begin(16,2); 
  pinMode(input,INPUT);
  /*
  pinMode(led10,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led1,OUTPUT);  
  */
  start_time=0;
  count=0;
  stop_time=0;
//  tone(34,35);// RPM 1050
  lcd.setCursor(0,0);
  lcd.print("RPM:");
}
void loop()
{
  
      start_time=pulseIn(input,HIGH);
      stop_time=start_time*4;
      RPM=(60000000/stop_time);
      Serial.println(RPM);
      lcd.setCursor(4,0);
      lcd.print(RPM);
   
        delay(30);
  }
