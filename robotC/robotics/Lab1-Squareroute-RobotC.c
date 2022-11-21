#define MetreTime 2900
#define Rotate90Time 357

int count = 0;
task main()
{

	while(count !=4)
	{
		// Move forward at half power for 1 metre
		setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to half power forward (50)
		setMotorSpeed(motorC, 50); 	//Set the rightMotor (motor6) to half power forward (50)
		sleep(2900);			//Wait for 1.5 seconds before continuing on in the program.

		// turn 90 degrees
		setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to Off
		setMotorSpeed(motorC, -50);  	//Set the rightMotor (motor6) to Off
		sleep(357);			//Wait for 0.357 seconds before continuing on in the program.

		count++;
	}

}
