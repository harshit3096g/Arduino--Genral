#define avgSpeedL 200 //185 is good
#define avgSpeedR 226
#define zeroSpeed 0
int pwmA = 3;
int pwmB = 11;
int dirA1 = 4;
int dirA2 = 5;
int dirB1 = 6;
int dirB2= 7;
int inp=12;
int inpu=2;
void setup(){
Serial.begin(9600);
pinMode(pwmA, OUTPUT);
pinMode(pwmB, OUTPUT);
pinMode(dirA1, OUTPUT);
pinMode(dirA2, OUTPUT);
pinMode(dirB1, OUTPUT);
pinMode(dirB2, OUTPUT);
pinMode(inp, INPUT);
pinMode(inpu, INPUT);
digitalWrite(dirA1,!HIGH);
digitalWrite(dirA2,HIGH);
digitalWrite(dirB1,HIGH);
digitalWrite(dirB2,!HIGH);
analogWrite(pwmA, avgSpeedL);
analogWrite(pwmB, avgSpeedR);
delay(500);
}
void loop(){
int inp1 = digitalRead( inp );
Serial.println(inp1);
int inpu1 = digitalRead( inpu );
Serial.println(inpu1);
if(inp1==!HIGH)
{
analogWrite(pwmA, zeroSpeed);
analogWrite(pwmB, zeroSpeed);
delay(10);
digitalWrite(dirA1,HIGH);
digitalWrite(dirA2,!HIGH);
digitalWrite(dirB1,HIGH);
digitalWrite(dirB2,!HIGH);
analogWrite(pwmA, avgSpeedL);
analogWrite(pwmB, avgSpeedR);
delay(200);
analogWrite(pwmA, zeroSpeed);
analogWrite(pwmB, zeroSpeed);
}
if(inpu1==!HIGH)
{
analogWrite(pwmA, zeroSpeed);
analogWrite(pwmB, zeroSpeed);
delay(10);
digitalWrite(dirA1,!HIGH);
digitalWrite(dirA2,HIGH);
digitalWrite(dirB1,!HIGH);
digitalWrite(dirB2,HIGH);
analogWrite(pwmA, avgSpeedL);
analogWrite(pwmB, avgSpeedR);
delay(200);
analogWrite(pwmA, zeroSpeed);
analogWrite(pwmB, zeroSpeed);
}
digitalWrite(dirA1,!HIGH);
digitalWrite(dirA2,HIGH);
digitalWrite(dirB1,HIGH);
digitalWrite(dirB2,!HIGH);
analogWrite(pwmA, avgSpeedL);
analogWrite(pwmB, avgSpeedR);

}


