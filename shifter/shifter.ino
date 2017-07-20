void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(2)==HIGH)
 {
while(digitalRead(2)==HIGH){
  // do something repetitive 200 times
  digitalWrite(10,1); 
 digitalWrite(11,0);
 delay(100);
}
 
 }

 
 else if(digitalRead(3)==HIGH)
 {
  while(digitalRead(3)==HIGH){
  // do something repetitive 200 times
 digitalWrite(11,1);
digitalWrite(10,0);
delay(100);
}
  
 }
 else
 {
 digitalWrite(10,0);
 digitalWrite(11,0);
 }
 delay(10);
}
