#define avgSpeedL 200 //185 is good
#define avgSpeedR 222
#define zeroSpeed 0
#define turnSpeed 110

#define RMotorSpeedPin 6
#define LMotorSpeedPin 3
#define RMotorDirA 7  //A is 1,4 and B is 2,3
#define RMotorDirB 5
#define LMotorDirA 4
#define LMotorDirB 2
#define FR 11    // L3 L2 FR BK R2 R3
#define L2 12
#define L3 13
#define BK 10
#define R2 9
#define R3 8
boolean DFR,DL2,DL3,DBK,DR2,DR3;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(RMotorDirA, OUTPUT);
  pinMode(RMotorDirB, OUTPUT);
  pinMode(LMotorDirA, OUTPUT);
  pinMode(LMotorDirB, OUTPUT);
  pinMode(LMotorSpeedPin, OUTPUT);
  pinMode(RMotorSpeedPin, OUTPUT);
  pinMode(FR, INPUT);
  pinMode(L2, INPUT);
  pinMode(L3, INPUT);
  pinMode(BK, INPUT);
  pinMode(R2, INPUT);
  pinMode(R3, INPUT);
  
  analogWrite(RMotorSpeedPin,avgSpeedR);
  analogWrite(LMotorSpeedPin,avgSpeedL);

  ForwardDirectionSet();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void ForwardDirectionSet(){//A is 1,4 and B is 2,3
  analogWrite(RMotorSpeedPin,avgSpeedR);
  analogWrite(LMotorSpeedPin,avgSpeedL);
digitalWrite(RMotorDirA,LOW);
digitalWrite(RMotorDirB,HIGH);
digitalWrite(LMotorDirA,LOW);
digitalWrite(LMotorDirB,HIGH);
}

void BackwardDirectionSet(){//A is 1,4 and B is 2,3
  analogWrite(RMotorSpeedPin,avgSpeedR);
  analogWrite(LMotorSpeedPin,avgSpeedL);
digitalWrite(RMotorDirA,HIGH);
digitalWrite(RMotorDirB,LOW);
digitalWrite(LMotorDirA,HIGH);
digitalWrite(LMotorDirB,LOW);
}

void RotateLeft(){//A is 1,4 and B is 2,3
  analogWrite(RMotorSpeedPin,turnSpeed);
  analogWrite(LMotorSpeedPin,turnSpeed);
digitalWrite(RMotorDirA,LOW);
digitalWrite(RMotorDirB,HIGH);
digitalWrite(LMotorDirA,HIGH);
digitalWrite(LMotorDirB,LOW);
}

void RotateRight(){//A is 1,4 and B is 2,3
  analogWrite(RMotorSpeedPin,turnSpeed);
  analogWrite(LMotorSpeedPin,turnSpeed);
digitalWrite(RMotorDirA,HIGH);
digitalWrite(RMotorDirB,LOW);
digitalWrite(LMotorDirA,LOW);
digitalWrite(LMotorDirB,HIGH);
}

void StopSet(){//A is 1,4 and B is 2,3
digitalWrite(RMotorDirA,HIGH);
digitalWrite(RMotorDirB,HIGH);
digitalWrite(LMotorDirA,HIGH);
digitalWrite(LMotorDirB,HIGH);
}
