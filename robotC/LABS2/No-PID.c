
//function prototype
void turn90degreesLeft();
void goForward1seconds();
void turn90degreesRight();
void swingLeft90degrees();
void swingRight90degrees();
void reverse1second();


//program start
task main()
{
	turn90degreesLeft();
	goForward1seconds();
	turn90degreesRight();
	goForward1seconds();
	swingLeft90degrees();
	swingRight90degrees();
	reverse1second();
}

void turn90degreesLeft()
{
	// turn 90 degrees
	setMotorSpeed(motorB, -50);	//Set the leftMotor (motor1) to reverse
	setMotorSpeed(motorC, 50);  	//Set the rightMotor (motor6) to forward
	sleep(357);			//Wait for 0.357 seconds before continuing on in the program.
}

void turn90degreesRight()
{
	// turn 90 degrees
	setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to forward
	setMotorSpeed(motorC, -50);  	//Set the rightMotor (motor6) to reverse
	sleep(357);			//Wait for 0.357 seconds before continuing on in the program.

}

void goForward1seconds()
{
	// Move forward at half power for 1 metre
		setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to half power forward (50)
		setMotorSpeed(motorC, 50); 	//Set the rightMotor (motor6) to half power forward (50)
		sleep(1000);			//Wait for 1.5 seconds before continuing on in the program.

}

void reverse1second()
{
	// Move forward at half power for 1 metre
		setMotorSpeed(motorB, -50);	//Set the leftMotor (motor1) to half power forward (50)
		setMotorSpeed(motorC, -50); 	//Set the rightMotor (motor6) to half power forward (50)
		sleep(1000);			//Wait for 1.5 seconds before continuing on in the program.

}
void swingLeft90degrees()
{
	setMotorSpeed(motorB, 43.5);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, 55); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(3250);
}
void swingRight90degrees()
{
	setMotorSpeed(motorB, 55);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(motorC, 43.5); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(3250);

}
