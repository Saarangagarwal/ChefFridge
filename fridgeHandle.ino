/*
 Distance Sensor
  This code reads an ultrasonic rangefinder and returns 1 if the distance of the
  sensor is less than 11 cm, otherwise it returns 0. An output is displayed to the
  console only if there is a change in the output returned by the above algorithm.
  Also, the calculated length of the returning pulse is proportional to the distance
  of the object from the sensor.
  The circuit:
 - +V connection of the sensor attached to +5V of arduino
 - GND connection of the sensor attached to ground of arduino
 - TRIG connection of the sensor attached to digital pin 7 of arduino
  - ECHO connection of the sensor attached to digital pin 6 of arduino
  Created by Saarang Agarwal, Satavanan and Sabeeh
*/

const int pingPin = 6; //pin number of the sensor's output
int var = 0; // comparison variable to detect change in output
void setup() {
  // initialize serial communication
  Serial.begin(9600);
  Serial.print("0");
  Serial.println();
}
  void loop() {
  long duration,cm;
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(5000);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5000);
  digitalWrite(pingPin, LOW);
  // The same pin is used to read the signal from the sensor: a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  int temp;
  if( (cm>=0) && (cm <11) )
  {
    temp=1;
  }
  else
  {
    temp=0;
  }
  if(temp!=var)
  {
    Serial.print(temp);
    Serial.println();
    var=temp;
  }
 
  delay(1000);
}
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
