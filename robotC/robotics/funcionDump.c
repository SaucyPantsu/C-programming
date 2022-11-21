#define WAIT 800
#define DISTANCE 325

//function prototype
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

int XCalculation(int StartX, int DestinationX)
{
	int Xdif =0;
	if(DestinationX > StartX)
	{
		Xdif = DestinationX - StartX;
	}

	else
	{
		Xdif = StartX - DestinationX;
	}

	return Xdif;
}

int YCalculation(int StartY, int DestinationY)
{
	int Ydif =0;
	if(DestinationY > StartY)
	{
		Ydif = DestinationY - StartY;
	}

	else
	{
		Ydif = StartY - DestinationY;
	}

	return Ydif;
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
task main()
{
	int count = 0;
	int StartX = 1;
	int StartY = 4;
	int GOTOx;
	int GOTOy;
	SensorType[S4] = sensorEV3_Gyro; // set sensor to port 4
	int State = 2;

	displayBigTextLine(3,"Set Destination");   // Useful command but not required


	while (getButtonPress(buttonEnter) == 0) // waiting for enter button to be pressed
	{

		displayCenteredBigTextLine(5, "destination :");
		displayCenteredBigTextLine(7, "%d, %d", GOTOx, GOTOy);
		displayCenteredBigTextLine(9, "Enter to Start");

		wait1Msec(200);
		if (getButtonPress(buttonUp))//go to 4,1
		{
			GOTOx = 4;
			GOTOy = 1;
			State = 0;
		}
		if(getButtonPress(buttonDown))//5,6
		{
			GOTOx = 5;
			GOTOy = 6;
			State = 1;
		}
	}
	eraseDisplay();

	if(State == 0)
	{
		Xtravel(GOTOx, GOTOy, StartX, StartY);
		//going 4,1
		turn90(-100);
		Ytravel(GOTOy, StartY, GOTOx);
	}

	if(State == 1)
	{
		Xtravel(GOTOx, GOTOy, StartX, StartY);
		turn90(100);
		Ytravel(GOTOy, StartY, GOTOx);
		//going 5,6
	}


}
