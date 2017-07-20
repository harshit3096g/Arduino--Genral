#include <LiquidCrystal.h>
LiquidCrystal lcd(22,23,24,25,26,27);
float start;
float elapsed; 
float circ=1.595929; //wheel circumference in metres
float speeed; 
unsigned long j=1;
 // for RPM 
unsigned long start_time;
unsigned long stop_time;
int RPM;
#define input 35 // input from ECU attaches to this pin

void setup(){
   attachInterrupt(digitalPinToInterrupt(21),speedo,RISING);  
  start=micros();
  
  Serial.begin(115200);
  lcd.begin(16,2); 
  pinMode(28,INPUT_PULLUP);//for Gear
  pinMode(29,INPUT_PULLUP);
  pinMode(30,INPUT_PULLUP);
  pinMode(31,INPUT_PULLUP);
  pinMode(32,INPUT_PULLUP);
  pinMode(33,INPUT_PULLUP);
  pinMode(34,INPUT);  //for Speed
  tone(21,441); 
  pinMode(input,INPUT); //for RPM  
  start_time=0;
  stop_time=0;
  
}

void speedo()
{
  j++;
  elapsed=micros()-start; //fluctuates
  start=micros();
  speeed=(3600000*circ)/(42*elapsed); //fluctuates
}


void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Speed:");
  lcd.print(int(speeed));
  
  lcd.setCursor(0,1);
  lcd.print("Gear:");
  
  
  if(digitalRead(28)==LOW){
    lcd.print("1");
  }
  
  else if(digitalRead(29)==LOW){
    lcd.print("2");
  }
  
  else if(digitalRead(30)==LOW){
    lcd.print("3");
   }
  
 else if(digitalRead(31)==LOW){
    lcd.print("4");
  }
  
  else if(digitalRead(32)==LOW){
    lcd.print("5");
  }
  
  else if(digitalRead(33)==LOW){
    lcd.print("6");
  }
  
  else{                     
    lcd.print("0");
  }
  
  lcd.setCursor(12,1);
  lcd.print((0.001595929*(j))/42);
  lcd.setCursor(7,1);
  lcd.print("Dist:");
  
   start_time=pulseIn(input,HIGH,300000000);
  stop_time=start_time*4;
  RPM=(60000000/stop_time);
  
  lcd.print((round((RPM)/100))*100);
  
    delay(200);
}
  
