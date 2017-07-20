#define RMotorSpeedPin 7
#define LMotorSpeedPin 4
#define RMotorDirA 6
#define RMotorDirB 5
#define LMotorDirA 3
#define LMotorDirB 2
int i=1;

void setup() {
  // put your setup code here, to run once:
pinMode(RMotorDirA, OUTPUT);
pinMode(RMotorDirB, OUTPUT);
pinMode(LMotorDirA, OUTPUT);
pinMode(LMotorDirB, OUTPUT);
pinMode(LMotorSpeedPin, OUTPUT);
pinMode(RMotorSpeedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(RMotorSpeedPin,80);
analogWrite(LMotorSpeedPin,80);

if (i==1){
ForwardDirectionSet();
i=0;
delay(1000);
}
else if (i==0){
BackwardDirectionSet();
i=1;
delay(1000);
}
}

void ForwardDirectionSet(){//A is 1,4 and B is 2,3
digitalWrite(RMotorDirA,LOW);
digitalWrite(RMotorDirB,HIGH);
digitalWrite(LMotorDirA,LOW);
digitalWrite(LMotorDirB,HIGH);
}

void BackwardDirectionSet(){//A is 1,4 and B is 2,3
digitalWrite(RMotorDirA,HIGH);
digitalWrite(RMotorDirB,LOW);
digitalWrite(LMotorDirA,HIGH);
digitalWrite(LMotorDirB,LOW);
}
