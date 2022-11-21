#define TIME 3500
#define SPEEDB 43.5
#define SPEEDC 65
task main()
{
	// Move forward at half power for 1.5 seconds
	setMotorSpeed(motorB, SPEEDB);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, SPEEDC); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(TIME);			//Wait for 1.5 seconds before continuing on in the program.
	
	setMotorSpeed(motorB, SPEEDC);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, SPEEDB); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(TIME);			//Wait for 1.5 seconds before continuing on in the program.
	
	setMotorSpeed(motorB, SPEEDC);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, SPEEDB); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(TIME);			//Wait for 1.5 seconds before continuing on in the program.		//Wait for 1.5 seconds before continuing on in the program.
	
	setMotorSpeed(motorB, SPEEDB);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, SPEEDC); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(TIME);			//Wait for 1.5 seconds before continuing on in the program.
	
}
