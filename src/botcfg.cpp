#include "botcfg.h"

// Define Servo Pins
const int armPin[2] = {18, 21};
const int gripperPin = 19;
const int rotatePin = 5;

// Define Servos
Servo armServo[2];
Servo gripperServo;
Servo rotateServo;

// Define L298N Motor Driver Pins (if needed, can be added here)
const int enA = 13; // Opsional: Enable pin for Motor A (if using motors)
const int in1 = 12;
const int in2 = 14;
const int enB = 27; // Opsional: Enable pin for Motor B (if using motors)
const int in3 = 26;
const int in4 = 25;

// Define Ultrasonic Sensor
const int trigPin = 32;
const int echoPin = 33;

// Initialize Hardware
void initBot()
{
    // Initialize Arm Servos
    for (int i = 0; i < 2; i++) {
        armServo[i].attach(armPin[i]);
    }
    
    // Initialize Gripper Servo
    gripperServo.attach(gripperPin);
    
    // Initialize Rotation Servo
    rotateServo.attach(rotatePin);

    // Initialize Motor Pins (if using motors)
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Initialize Ultrasonic
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

// =============== Test Functions Only ===============
void servoTest()
{
    // Test Arm
    for (int i = 0; i < 2; i++) {
        armServo[i].write(90);
        delay(1000);
        armServo[i].write(0);
        delay(1000);
    }
    
    // Test Gripper
    gripperServo.write(90);
    delay(1000);
    gripperServo.write(0);
    delay(1000);
    
    // Test Rotation
    rotateServo.write(90);
    delay(1000);
    rotateServo.write(0);
    delay(1000);
}

void ultrasonicTest()
{
    // Send Trigger Pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read Echo Pulse
    long duration = pulseIn(echoPin, HIGH);
    
    // Calculate Distance (in cm)
    long distance = duration * 0.034 / 2;
    
    // Print Distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000);
}

void motorTest()
{
    // Example: Move Motor A Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 255); // Full speed
    delay(2000); // Run for 2 seconds

    // Stop Motor A
    analogWrite(enA, 0);
    delay(1000);

    // Example: Move Motor B Backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 255); // Full speed
    delay(2000); // Run for 2 seconds

    // Stop Motor B
    analogWrite(enB, 0);
    delay(1000);
}

// ==================== Functions ====================

void moveArm(int armIndex, int angle)
{
    if (armIndex >= 0 && armIndex < 2) {
        armServo[armIndex].write(angle);
    }
}

void Gripping(int angle)
{
    gripperServo.write(angle);
}

void rotateArm(int angle)
{
    rotateServo.write(angle);
}

void detectObject()
{
    // Send Trigger Pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read Echo Pulse
    long duration = pulseIn(echoPin, HIGH);
    
    // Calculate Distance (in cm)
    long distance = duration * 0.034 / 2;
    
    // Check if Object is Detected within 20 cm
    if (distance > 0 && distance < 20) {
        Serial.println("Object Detected!");
        // You can add additional actions here (e.g., move arm, rotate, etc.)
    } else {
        Serial.println("No Object Detected.");
    }

    // Print Distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
}