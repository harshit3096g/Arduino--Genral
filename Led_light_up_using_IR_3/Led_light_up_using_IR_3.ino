#include <IRremote.h>



#define PIN_IR 3
#define PIN_DETECT 7
#define PIN_STATUS 13
// ms that beam will be disabled 
#define BEAM_OFF_TIME 60


IRsend irsend;

int count;
boolean detected = false;

unsigned long timeStamp = 0;

void setup()
{
Serial.begin(57600);
pinMode(PIN_IR, OUTPUT);
pinMode(PIN_DETECT, INPUT);
pinMode(PIN_STATUS, OUTPUT);
irsend.enableIROut(38);
}

void loop() {

if (millis()-timeStamp > BEAM_OFF_TIME) {
detected = false;
irsend.enableIROut(38);
} 
if (!detected) {
irsend.space(0);
delay(1);
irsend.mark(0);
delay(1);
detected = !digitalRead(PIN_DETECT);
if (detected) {
digitalWrite(PIN_IR, LOW);
}
digitalWrite(PIN_STATUS, detected);
Serial.println(detected);
timeStamp = millis();
}

}
