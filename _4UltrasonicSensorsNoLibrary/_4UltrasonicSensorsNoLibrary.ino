#define trigPin1 46
#define echoPin1 47
#define trigPin2 48
#define echoPin2 49
#define trigPin3 50
#define echoPin3 51
#define trigPin4 52
#define echoPin4 53

long duration, distance, RightSensor,FRSensor,FLSensor,LeftSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
FRSensor = distance;
SonarSensor(trigPin3, echoPin3);
FLSensor = distance;
SonarSensor(trigPin4, echoPin4);
LeftSensor = distance;

Serial.print(RightSensor);
Serial.print(" - ");
Serial.print(FRSensor);
Serial.print(" - ");
Serial.print(FLSensor);
Serial.print(" - ");
Serial.println(LeftSensor);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH, 37000);
distance = (duration/2) / 29.1;
if (distance>300 || distance==0)
distance=300;
else 
distance=distance;
}
