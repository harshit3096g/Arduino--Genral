#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,8,10);
# define input 2
float RPM;
int count;
unsigned long start_time;
unsigned long now_time;
unsigned long end_time;
int m=0;

void setup(){
 Serial.begin(115200);
lcd.begin(16,2);
 pinMode(input,INPUT);
 attachInterrupt(digitalPinToInterrupt(2),counter,RISING);
 tone(9,35);
lcd.setCursor(1,0);
 lcd.print("RPM:");
}

void counter(){
  if (m==0)
  {start_time=millis();}
  now_time=millis();
  end_time=now_time-start_time;
  m=m+1;
 if(end_time>=600)
  {
  Serial.println(50*m);
lcd.setCursor(5,0);
 lcd.print((50*m)-100);
  m=0;
} 
}


void loop(){
  
}  
