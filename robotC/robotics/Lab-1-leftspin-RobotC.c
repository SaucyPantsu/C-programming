#define TIMEMOVE 1450
#define TIMETURN 1428
task main()
{
	// Move forward at half power for 0.5 metres
		setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to half power forward (50)
		setMotorSpeed(motorC, 50); 	//Set the rightMotor (motor6) to half power forward (50)
		sleep(TIMEMOVE);			//Wait timemove amount of Mseconds

		// turn 360
		setMotorSpeed(motorB, 50);	//Set the leftMotor (motor1) to Off
		setMotorSpeed(motorC, -50);  	//Set the rightMotor (motor6) to Off
		sleep(TIMETURN);			//Wait for 0.409 seconds before continuing on in the program.



}
