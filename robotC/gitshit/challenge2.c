//definitions
#define WAIT 550
#define TEST 5000
#define QUARTER43 100
//function prototype

void drive(long motorRatio,long dist, long power)
{
	setMotorSyncEncoder(motorB, motorC, motorRatio, dist, power);
}

void turn90()
{
	int Angle;

	wait1Msec(1000);
	resetGyro(S4);
	wait1Msec(1000);

	setMotorSync(motorB, motorC,100, 10);

	while (abs(getGyroDegrees(S4))<90)
	{
		sleep(1);
		Angle=getGyroDegrees(S4);
		displayCenteredBigTextLine(5,"current angle %4d",Angle);
	}

	playTone(440,10);
	setMotorSync(motorB, motorC, 0, 0); // stop the motors
	wait1Msec(1000);      // Allow sensor to settle
}


task main()
{
	int touch = 0;
	int count = 0;
	int distance = QUARTER43;

	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S4] = sensorEV3_Gyro; // set sensor to port 4
	sleep(1000);
	resetGyro(S4);
	sleep(2000);

	count = getUSDistance(S2);
	//going to first wall
	while(count >10)
	{

		drive(0, distance, 50);
		sleep(20);
		count = getUSDistance(S2);

	}
	turn90();
	sleep(WAIT);

	//touching second wall
	touch = getTouchValue(S1);
	while (touch != 1)
	{
		drive(0, distance, 50);
		sleep(20);
		touch = getTouchValue(S1);
	}
	drive(0, 10, -20);
	turn90();
	sleep(WAIT);

	//third wall
	count = getUSDistance(S2);
	while(count > 4)
	{

		drive(0, distance, 50);
		sleep(20);
		count = getUSDistance(S2);

	}
	drive(0, 10, -20);
	//final travel
	turn90();
	sleep(WAIT);
	drive(0, distance*8, 50);
	sleep(2000);
}
