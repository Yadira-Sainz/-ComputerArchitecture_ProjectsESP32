#include <ESP32Servo.h>

Servo rigthlegservo;

void setup(){
  rigthlegservo.attach(14);
}

void loop(){
  rigthlegservo.write(180);
  delay(2000);
  rigthlegservo.write(0);
  delay(2000);
}