// My Libraries
# include "botcfg.h"

// Setup function runs once at startup
void setup()
{
    // Start Serial Communication
    Serial.begin(115200);
    
    // Initialize Bot Hardware
    initBot();
    
    // Run Servo Test
    servoTest();

    // Run Ultrasonic Test
    ultrasonicTest();

    // Run Motor Test (if you have motors to test)
    motorTest();
}

// Loop/Update next program
void loop()
{
    detectObject();

    Serial.println("Running Arm 0");
    moveArm(0, 90); // Move Arm 0 to 90 degrees
    delay(1000); // Delay for 1 second before next action
    moveArm(0, 0);  // Move Arm 0 back to 0 degrees
    delay(1000); // Delay for 1 second before next check
    Serial.println("Running Arm 1");
    moveArm(1, 90); // Move Arm 1 to 90 degrees
    delay(1000); // Delay for 1 second before next action
    moveArm(1, 0);  // Move Arm 1 back to 0 degrees
    delay(1000); // Delay for 1 second before next check

    Serial.println("Running Gripper");
    Gripping(90); // Move Gripper to 90 degrees
    delay(1000); // Delay for 1 second before next action
    Gripping(0);  // Move Gripper back to 0 degrees
    delay(1000); // Delay for 1 second before next check

    Serial.println("Running Rotation");
    rotateArm(90); // Rotate Arm to 90 degrees
    delay(1000); // Delay for 1 second before next action
    rotateArm(0);  // Rotate Arm back to 0 degrees
    delay(1000); // Delay for 1 second before next check
}