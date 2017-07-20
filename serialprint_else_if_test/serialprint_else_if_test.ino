#define upshift 3
#define downshift 4
#define neutral 5  



unsigned int u = 0; 
unsigned int d = 0; 
unsigned int n = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(upshift, INPUT); //upshift input to arduino
  pinMode(downshift, INPUT); //  downshift input to arduino
  pinMode(neutral, INPUT);     // Neutral Input to arduino. 
}

void loop() {
  // put your main code here, to run repeatedly:
  u = 0;
  d = 1;
  n = 1;

  if (u == HIGH)
  {
   Serial.println("if"); 
  }
  // down shift code
  else if (d == HIGH)
  {
  Serial.println("else if");
  }
  //neutral code
  else
  {
   Serial.println("else");
  }
}
