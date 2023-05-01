#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
int servo1counter = 90;
int servo2counter = 90;
int servo3counter = 90;
int servo1step = 10;
int servo2step = 13;
int servo3step = 17;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  //servo1.write(90);
  servo1.write(analogRead(A0)/1023.0*300-102);
  servo2.write(analogRead(A1)/1023.0*300-102);
  //Serial.println(analogRead(A0)/1023.0*180);
  //Serial.println(analogRead(A1)/1023.0*180);
  Serial.println();
  //servo3.write(servo3counter);
  //servo1counter += servo1step;
  //servo2counter += servo2step;
  //servo3counter += servo3step;
  /*
  if (servo1counter < 0 or servo1counter > 180) {
    servo1counter = servo1counter * -1;    
  }
  if (servo2counter < 0 or servo2counter > 180) {
    servo2counter = servo2counter * -1;    
  }
  if (servo3counter < 45 or servo3counter > 135) {
    servo3counter = servo3counter * -1;    
  }*/
  delay(15);
}