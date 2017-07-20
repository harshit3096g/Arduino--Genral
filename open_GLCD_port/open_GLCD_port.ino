#include <openGLCD.h>
#include <openGLCD_Buildinfo.h>
#include <openGLCD_Config.h>


//LiquidCrystal lcd(12,11,5,4,3,10); dont need this in GLCD
float start; 
float elapsed; 
float circ=1.595929; //wheel circumference in metres
float speeed; 
unsigned long j=0; 

void setup(){
  GLCD.Init();
  GLCD.SelectFont(System5x7);
  GLCD.ClearScreen();
  attachInterrupt(digitalPinToInterrupt(2),speedo,RISING);
  start=micros();
  Serial.begin(115200);
  //lcd.begin(16,2); not needed in GLCD
  tone(9,441); //tone no response above 500
  pinMode(0,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  
}

void speedo(){
  j++;
  elapsed=micros()-start; //fluctuates
  start=micros();
  speeed=(3600*circ)/(42*elapsed); //fluctuates

}

void loop(){
  GLCD.ClearScreen();
  GLCD.CursorTo(0,0);
  GLCD.print("Speed:");
  GLCD.print(int(speeed));
  
  GLCD.CursorTo(0,1);
  GLCD.print("Gear:");
  
  
  if(digitalRead(0)==LOW){
    GLCD.print("1");
  }
  
  else if(digitalRead(8)==LOW){
    GLCD.print("2");
  }
  
  else if(digitalRead(6)==LOW){
    GLCD.print("3");
   }
  
 else if(digitalRead(7)==LOW){
    GLCD.print("4");
  }
  
  else{
    GLCD.print("0");
  }
  
  GLCD.CursorTo(12,1);
  GLCD.print((0.001595929*(j-1))/42);
  GLCD.CursorTo(7,1);
  GLCD.print("Dist:");
    delay(200);
}
  
