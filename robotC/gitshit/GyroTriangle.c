const float DEGREESTOCM = 360/17.3;
// calculate degrees for a CM based on measurement of distance wheel travels in 1 rotation


// Convert distance to degrees
float distanceInDegrees(long distance)
{
	return distance*DEGREESTOCM;
}

void turn90(){

	int Angle;

	wait1Msec(1000);
	resetGyro(S4);
	wait1Msec(1000);

	setMotorSync(motorB, motorC, -100, 10);

	while (abs(getGyroDegrees(S4))<120)
	{
		sleep(1);
		Angle=getGyroDegrees(S4);
		displayCenteredBigTextLine(5,"current angle %4d",Angle);
	}

	playTone(440,10);
	setMotorSync(motorB, motorC, 0, 0); // stop the motors
	wait1Msec(1000);      // Allow sensor to settle
}

// Move forward a set distance
void triangle(long dist, long power)
{
	float degreesToTurn = 0;
	degreesToTurn = distanceInDegrees(dist);
	displayBigTextLine(7,"Power %d",power);

	for (int i = 0; i<=2; i++) {
		setMotorSyncEncoder(motorB, motorC, 0, degreesToTurn, power);
		//waitUntilMotorStop(motorB);  // Only use with Physcial Robot
		wait1Msec(2000);
		turn90();
	}
}


task main()
{
	SensorType[S4] = sensorEV3_Gyro;  // Sensor set to port 4
	long distance = 0;
	long power = 0;
	displayBigTextLine(1,"Lab5 GyroTriangle");   // Useful command but not required
	displayBigTextLine(3,"Calibrating");   // Useful command but not required

	wait1Msec(2000);
	resetGyro(S4);   // Set the sensor value to 0
	wait1Msec(2000);


	setLEDColor(ledRedFlash);
	displayBigTextLine(3,"Set Dist");   // Useful command but not required


	while (getButtonPress(buttonEnter) == 0) // waiting for enter button to be pressed
	{

		displayCenteredBigTextLine(5, "Dist is  %d cm",distance);
		displayCenteredBigTextLine(7, "Enter to Start");

		wait1Msec(200);
		if (getButtonPress(buttonUp))
			distance = 10;
		else if (getButtonPress(buttonDown))
			distance = 20;
		else if (getButtonPress(buttonLeft))
			distance = 25;
		else if (getButtonPress(buttonRight))
			distance = 40;
	}

	setLEDColor(ledGreenFlash);

	displayCenteredBigTextLine(5, "Dist =  %d cm",distance);
	triangle(distance ,60);     // drive the requried distance

}
