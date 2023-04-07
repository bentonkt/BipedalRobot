#include <Servo.h>
#include <Adafruit_LSM6DSOX.h>
#include <math.h>

float a = 106;
float b = 144.5;
float d;

void calculateJointAngles(float x, float y, float &theta1, float &theta2) {

    d = sqrt(x * x + y * y);

    if (d > (a + b)) {
        Serial.println("Error: The target point is unreachable.");
        return;
    }

    float alpha = acos((a * a + d * d - b * b) / (2 * a * d));

    float beta = acos((a * a + b * b - d * d) / (2 * a * b));

    theta2 = M_PI - beta;

    theta1 = atan2(y, x) - atan2((b * sin(theta2)), a + b * cos(theta2));

    theta1 = theta1 * 180.0 / M_PI;
    theta2 = theta2 * 180.0 / M_PI;
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    float x = 100; 
    float y = 100;
    float theta1, theta2;

    calculateJointAngles(x, y, theta1, theta2);

    Serial.print("Theta1: ");
    Serial.print(theta1, 2);
    Serial.print("°, Theta2: ");
    Serial.print(theta2, 2);
    Serial.println("°");

    delay(1000); 
}
