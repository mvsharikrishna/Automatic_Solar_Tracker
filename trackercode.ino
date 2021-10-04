#include<Servo.h>
Servo myservo;
int initialpos=0;
int LDR1=A0;
int LDR2=A1;
int servopin=10;
void setup() {

  //set the pin mode for the motor to be an output
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   myservo.attach(servopin);
   myservo.write(initialpos);
   Serial.begin(9600);
}
void loop() {
 int sensorValue = analogRead(A0);
 int sensorValue1 = analogRead(A1);
 float volt1=sensorValue*(5.0/1023.0);
 float volt2=sensorValue1*(5.0/1023.0);
 if (volt1 > volt2){
    initialpos=initialpos-1;
 }
 else if (volt2 > volt1){
    initialpos=initialpos+1;
 }
 else if(volt2 == volt1){
  digitalWrite(servopin,LOW);
 }
myservo.write(initialpos);
  //print voltages

 Serial.print("sensorValue: ");
 Serial.println(volt1);
 Serial.print(' ');
 Serial.print("sensorValue1: ");
 Serial.println(volt2);
 Serial.print('\n');
  delay (100);
}
