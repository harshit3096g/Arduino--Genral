#include <SharpIR.h>

#define ir1 A0
#define ir2 A1
#define model 20150
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            (working distance range according to the datasheets)

SharpIR SharpIR1(ir1, model);
SharpIR SharpIR2(ir2, model);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  delay(300);   

  int dis1=SharpIR1.distance();  // this returns the distance to the object you're measuring
  int dis2=SharpIR2.distance();  // this returns the distance to the object you're measuring
 
  if (dis1>120){
    dis1=150;
  }
  else if(dis1>=0 && dis1<17){
    dis1=0;
  }
  if (dis2>120){
    dis2=150;
  }
  else if(dis2>=0 && dis2<17){
    dis2=0;
  }
  
  Serial.print("IR Disr A: ");  // returns it to the serial monitor
  Serial.print(dis1);
  Serial.print("      IR Disr B: ");  // returns it to the serial monitor
  Serial.println(dis2);
}
