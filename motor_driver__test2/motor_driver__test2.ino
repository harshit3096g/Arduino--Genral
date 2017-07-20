int i;

void setup() {
pinMode(2,1);
pinMode(3,1);
pinMode(4,1);
pinMode(5,1);
pinMode(9,1);
pinMode(11,1);

}

void loop() {
  for(i=10;i<=100;i+=10){
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
analogWrite(9,30+i);
analogWrite(11,30+i);
delay(5000);
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
analogWrite(9,0);
analogWrite(11,0);
delay(5000);
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
analogWrite(9,90+i);
analogWrite(11,90+i);
delay(5000);
digitalWrite(2,1);
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
analogWrite(9,0);
analogWrite(11,0);
delay(5000);
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
analogWrite(9,150+i);
analogWrite(11,150+i);
delay(5000);
digitalWrite(2,1);
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
analogWrite(9,100);
analogWrite(11,100);
delay(5000);
  }
}
