#ifndef BOTCFG_H
#define BOTCFG_H

// Extend Libraries
# include <ESP32Servo.h>

// Define Servo Pins
extern const int armPin[2];
extern const int gripperPin;
extern const int rotatePin;
// Define Servos
extern Servo armServo[2];
extern Servo gripperServo;
extern Servo rotateServo;

// Define Ultrasonic Sensor Pins
extern const int trigPin;
extern const int echoPin;

// Define L298N Motor Driver Pins (if needed, can be added here)
extern const int enA;
extern const int in1;
extern const int in2;
extern const int enB;
extern const int in3;
extern const int in4;

// Test Functions Only
void servoTest();
void ultrasonicTest();
void motorTest(); // If you have motors to test, you can implement this function

// Function Prototypes
void initBot();
void moveArm(int armIndex, int angle);
void Gripping(int angle);
void rotateArm(int angle);
void detectObject();

#endif // BOTCFG_H