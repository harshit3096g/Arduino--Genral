int i=35;
void setup() {
  // put your setup code here, to run on
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (i<=737)
{
  i++;
}
else
{
  i=35;
  }
  tone(9,i);
  Serial.println(i);
  delay(100);


  }
