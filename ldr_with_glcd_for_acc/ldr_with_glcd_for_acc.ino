#include <openGLCD.h>
 unsigned long a=0,b=0,c=0;
  int i=0;


void setup()
{
  // Initialize the GLCD 
  GLCD.Init();

Serial.begin(9600);
 // Select the font for the default text area
  GLCD.SelectFont(System5x7);
  GLCD.print("Initialising");
  delay(1000); 
 GLCD.ClearScreen();
}

void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 
 if(i==0)
{GLCD.CursorTo(0, 0);
   GLCD.print("READY");
   }

   Serial.println(analogRead(7));
   if(analogRead(7)>500)
{ 
  b=a;
  a=millis();
  Serial.println(a);
  c=a-b;
  i++;
  delay(10);
  if(i=1){
  GLCD.CursorTo(0, 0);
   GLCD.print("START");
    delay(3800);
   }
 if(i=2)
 {
 GLCD.ClearScreen();
   GLCD.CursorTo(0, 0);
   GLCD.print("STOP");
   GLCD.CursorTo(0, 1);
  GLCD.print(c);
  delay(4000);
   GLCD.ClearScreen();
   i=0;
 }
}

 }

