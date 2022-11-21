#define WAIT 800
#define DISTANCE 325

//function prototype

void Xtravel(int GOTOx, int GOTOy, int StartX, int StartY)
{
    int count = StartX-1;
		while(count <= GOTOx+1)
		{
			drive(0, DISTANCE, 50);
			sleep(600);
			displayCenteredBigTextLine(4,"Location is :");
			displayCenteredBigTextLine(7, "%d, %d", (count+1),StartY);
			playTone(440,10);
			count = count + 1;
		}
}
void Ytravel(int GOTOy, int StartY, int GOTOx)
{
    int count = StartY-1;
		while(count <GOTOy)
		{
			drive(0, DISTANCE, 50);
			sleep(600);
			displayCenteredBigTextLine(4,"Location is :");
			displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count+1));
			count = count + 1;
		}
}

void drive(long motorRatio,long dist, long power)
{
	setMotorSyncEncoder(motorB, motorC, motorRatio, dist, power);
}

void turn90(int MotorRatio)
{
	int Angle;

	wait1Msec(3000);
	resetGyro(S4);
	wait1Msec(1000);

	setMotorSync(motorB, motorC, MotorRatio, 30);

	while (abs(getGyroDegrees(S4))<80)
	{
		sleep(1);
		Angle=getGyroDegrees(S4);
	}

	playTone(440,10);
	setMotorSync(motorB, motorC, 0, 0); // stop the motors
	wait1Msec(2000);      // Allow sensor to settle
}

task main()
{
    int count = 0;
	int StartX = 3;
	int StartY = 1;
	int GOTOx = 3;
	int GOTOy = 7;
	SensorType[S4] = sensorEV3_Gyro; // set sensor to port 4
	int State = 2;

//step 1
    turn90(100);
    Ytravel(GOTOy, StartY, GOTOx);
    turn90(-100);
    turn90(100);
    turn90(100);
}