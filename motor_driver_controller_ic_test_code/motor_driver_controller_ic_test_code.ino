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
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);

for(i=1;i<=255;i++){
analogWrite(9,i);
analogWrite(11,i);
delay(10);
   }
   for(i=255;i>=1;i--){
analogWrite(9,i);
analogWrite(11,i);
delay(10);
   }
for(i=i;i<=255;i++){
digitalWrite(2,1);
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
analogWrite(9,i);
analogWrite(11,i);
delay(10);
   }
   
for(i=1;i<=255;i++){
digitalWrite(2,0);
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
analogWrite(9,i);
analogWrite(11,i);
delay(10);
   }
for(i=i;i<=255;i++){
digitalWrite(2,0);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
analogWrite(9,i);
analogWrite(11,i);
delay(10000);   
}   
}
