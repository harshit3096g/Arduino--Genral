#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,10);
float start; //removed finished
float elapsed; 
float circ=1.595929; //wheel circumference in metres
float speeed; 
unsigned long j=1; //made this long from int

void setup(){
   attachInterrupt(digitalPinToInterrupt(2),speedo,RISING);  
  start=micros();
  
  Serial.begin(115200);
  lcd.begin(16,2); 
  pinMode(0,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(2,INPUT);
  tone(9,2000); 
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
  
  
  if(digitalRead(0)==LOW){
    lcd.print("1");
  }
  
  else if(digitalRead(8)==LOW){
    lcd.print("2");
  }
  
  else if(digitalRead(6)==LOW){
    lcd.print("3");
   }
  
 else if(digitalRead(7)==LOW){
    lcd.print("4");
  }
  
  else{                     
    lcd.print("0");
  }
  
  lcd.setCursor(12,1);
  lcd.print((0.001595929*(j))/42);
  lcd.setCursor(7,1);
  lcd.print("Dist:");
  Serial.println(j);
    delay(200);
}
  
