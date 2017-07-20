/*
CR 16 Gear Shift Code 1.0
Edited by: Rahul and Deepak
date: 08-01-2016  11:58:19.
*/

#define upshift 2          //UP_SHIFT BUTTON
#define downshift 3        //DOWN_SHIFT BUTTON
#define neutral 4           //NEUTRAL_BUTTON
#define neutral_up 7       //NEUTRAL_UP RELAY (12V)
#define neutral_down 8      //NEUTRAL_DOWN RELAY (12V)
#define up_relay 9          //GEAR_UP RELAY  (24V)
#define down_relay 10        //GEAR_DOWN RELAY (24V)
#define clutch_engage 11      //CLUTCH_ENGAGE RELAY (24)
#define clutch_release 12     //CLUTCH_DISENGAGE RELAY (24V)

void setup()
{


  pinMode(upshift, INPUT); //upshift input to arduino
  pinMode(downshift, INPUT); //  downshift input to arduino
  pinMode(neutral, INPUT);     // Neutral Input to arduino.
  pinMode(neutral_up, OUTPUT);  // Neutral_up output
  pinMode(neutral_down, OUTPUT);   //Neutral_down output
  pinMode(up_relay, OUTPUT); // 3 is gear up shift
  pinMode(down_relay, OUTPUT); // 5 gear is downshift
  pinMode(clutch_engage, OUTPUT); // 6 is clutch engage
  pinMode(clutch_release, OUTPUT); //9 is clutch release
}

void loop()
{
 int u = digitalRead(upshift); //check if button is pressed
 int d = digitalRead(downshift); //check if button is pressed
 int n = digitalRead(neutral);    //check if button is pressed
  //up shift code
  if (u == HIGH)
  {
    digitalWrite(downshift, LOW); // Downshift button is disabled
    digitalWrite(clutch_engage, HIGH); // clutch is engaged
    delay(500); // engaging time
    digitalWrite(up_relay, HIGH); // Gear up shift takes place
    delay(200); // gear engaging time
    digitalWrite(clutch_engage, LOW); // turn of engaging system
    digitalWrite(up_relay, LOW); //turn of shifting system
    digitalWrite(clutch_release, HIGH); // clutch is released
    delay(50); // time to release
    digitalWrite(clutch_release, LOW); // turn of releasing system
  }
  // down shift code
  else if (d == HIGH)
  {
    digitalWrite(upshift, LOW); // upshift button is disabled
    digitalWrite(clutch_engage, HIGH); // clutch is engaged
    delay(500); // engaging time
    digitalWrite(down_relay, HIGH); // Gear down shift takes place
    delay(200); // gear engaging time
    digitalWrite(clutch_engage, LOW); // turn of engaging system
    digitalWrite(down_relay, LOW); //turn of shifting system
    digitalWrite(clutch_release, HIGH); // clutch is released
    delay(50); // time to release
    digitalWrite(clutch_release, LOW); // turn of releasing system
  }
  //neutral code
  else
  {
    /*
    check which gear it is in and then shift accordingly.
    if in first gear up shift using by activating up shift relay
    if in second gear then down shift by activating downshift relay.
    */
  }
}
