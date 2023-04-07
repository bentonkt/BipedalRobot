#include <Servo.h>
#include <Adafruit_LSM6DSOX.h>
#include <math.h>

// For SPI mode, we need a CS pin
#define LSM_CS 10
// For software-SPI mode we need SCK/MOSI/MISO pins
#define LSM_SCK 13
#define LSM_MISO 12
#define LSM_MOSI 11

Adafruit_LSM6DSOX sox;

Servo left_hip_1;
Servo left_hip_2;
Servo left_hip_3;
Servo left_knee; // higher is back
Servo left_ankle_1;
Servo left_ankle_2;
Servo right_hip_1;
Servo right_hip_2;
Servo right_hip_3;
Servo right_knee; // Higher is forward
Servo right_ankle_1;
Servo right_ankle_2;

float a = 106;
float b = 144.5;
float A = 90;
float B;
float kneeAngle;
float left_hip_2_angle;
float left_knee_angle;
float left_ankle_2_angle;
float right_hip_2_angle;
float right_knee_angle;
float right_ankle_2_angle;
bool increasing = false;
float increment = 0.1;


float getAnkleAngle(float A, float a, float b) {
  return M_PI/2 - asin(a * sin(M_PI/2-A) / b);
}

float getRadians(float x) {
  return x * M_PI / 180;
}

float getDegrees(float x) {
  return x * 180 / M_PI;
}


void setup() {

  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit LSM6DSOX test!");

  if (!sox.begin_I2C()) {
    // if (!sox.begin_SPI(LSM_CS)) {
    // if (!sox.begin_SPI(LSM_CS, LSM_SCK, LSM_MISO, LSM_MOSI)) {
    // Serial.println("Failed to find LSM6DSOX chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("LSM6DSOX Found!");

  left_hip_1.attach(2);
  left_hip_2.attach(3);
  left_hip_3.attach(4);
  left_knee.attach(5);
  left_ankle_1.attach(6);
  left_ankle_2.attach(7);
  right_hip_1.attach(8);
  right_hip_2.attach(9);
  right_hip_3.attach(10);
  right_knee.attach(11);
  right_ankle_1.attach(12);
  right_ankle_2.attach(13);
}

void loop() {
  left_hip_1.write(97); //97 + is curve in - is curve out
  left_hip_2.write(93); //93 + is back - is forward
  left_hip_3.write(90); //90 + is in - is out
  left_knee.write(32); //32 + is back - is forward
  left_ankle_1.write(95); //95 + is in - is out
  left_ankle_2.write(95); //95 + is back - is forward

  right_hip_1.write(90); //90 + is curve out - is curve in
  right_hip_2.write(105); //105 + is forward - is back
  right_hip_3.write(90); //90 + is out - is in
  right_knee.write(148); //148 + is forward - is back
  right_ankle_1.write(90); //90 + is in - is out
  right_ankle_2.write(75); //75 + is forward - is back
  /*

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  sox.getEvent(&accel, &gyro, &temp);

  Serial.print(temp.temperature);
  Serial.print(",");

  Serial.print(accel.acceleration.x);
  Serial.print(","); Serial.print(accel.acceleration.y);
  Serial.print(","); Serial.print(accel.acceleration.z);
  Serial.print(",");

  Serial.print(gyro.gyro.x);
  Serial.print(","); Serial.print(gyro.gyro.y);
  Serial.print(","); Serial.print(gyro.gyro.z);
  Serial.println();
  delayMicroseconds(10000);*/
  if (increasing) {
    A += increment;
  }
  else {
    A -= increment;
  }
  if (A <= 10) {
    //Serial.println("sitting down, increasing");
    increasing = true;
  }
  /*
  if (left_hip_2_angle < 0) {
    Serial.println("left_hip_2 past 0, increasing");
    increasing = true;
  }
  else if (left_knee_angle > 180) {
    Serial.println("left_knee past 180, decreasing");
    increasing = false;
  }
  else if (left_ankle_2_angle < 0) {
    Serial.println("left_ankle_2 past 0, increasing");
    increasing = true;
  }
  else if (right_hip_2_angle > 180) {
    Serial.println("right_hip_2 past 180, decreasing");
    increasing = false;
  }
  else if (right_knee_angle < 0) {
    Serial.println("right_knee past 0, increasing");
    increasing = true;
  }
  else if (right_ankle_2_angle > 180) {
    Serial.println("right_ankle_2 past 180, decreasing");
    increasing = false;
  }
  */
  else if (A >= 90) {
    //Serial.println("standing up, decreasing");
    increasing = false;
  }
  delay(1);
}