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

    // Run Motor Test
    motorTest();
}

// Loop/Update next program
void loop()
{
    bool objectDetected = detectObject(); // Update the detection result

    if (objectDetected) { // Check if an object is detected
        runMotor(0, 1);     // Stop motor
        // Sample actions when an object is detected
        moveArm(0, 90);     // Move Arm 1 to 90 degrees
        moveArm(1, 90);     // Move Arm 2 to 90 degrees
        Gripping(90);       // Close Gripper
        rotateArm(90);      // Rotate Arm to 90 degrees
        delay(500);         // Wait for 0.5 seconds
        // Return to initial position
        moveArm(0, 0);      // Move Arm 1 back to 0 degrees
        moveArm(1, 0);      // Move Arm 2 back to 0 degrees
        Gripping(0);        // Open Gripper
        rotateArm(0);       // Rotate Arm back to 0 degrees
        delay(500);         // Wait for 0.5 seconds
    } else {
        // If no object is detected, you can add idle behavior here
        runMotor(255, 1);   // Move forward at full speed
    }
    delay(500); // Delay for a while before the next detection
}