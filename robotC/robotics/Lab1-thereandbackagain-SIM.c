#define Rotate90Time 409

task main()
{
	// Move forward at half power for 5 seconds
	setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, 50); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(5000);			//Wait for 5 seconds before continuing on in the program.

	// Spin 180
	setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to Off
	setMotorSpeed(motorC, -50);  	//Set the rightMotor (motor6) to Off
	sleep(Rotate90Time*2);			//Wait for 0.818 seconds before continuing on in the program.

	// Move forward at half power for 5 seconds
	setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, 50); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(5000);			//Wait for 5 seconds before continuing on in the program.
}
