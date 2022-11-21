#define WAIT 800

//function prototype
void drive(long motorRatio,long dist, long power)
{
	setMotorSyncEncoder(motorB, motorC, motorRatio, dist, power);
}

void turn90(int MotorRatio)
{
	int Angle;

	wait1Msec(1000);
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
	wait1Msec(1000);      // Allow sensor to settle
}

int XCalculation(int StartX, int DestinationX)
{
	int Xdif =0;
	if(DestinationX > Startx)
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
		Xdif = StartY - DestinationY;
	}

	return Ydif;
}
task main()
{
	int count = 0;
	int StartX = 1;
	int StartY = 4;
	int GOTOx;
	int GOTOy;
	SensorType[S4] = sensorEV3_Gyro; // set sensor to port 4
	int Xdif = 10;
	int Ydif;
	int whileloop = 0;
	int distance = 100;

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
		}
		if(getButtonPress(buttonDown))//5,6
		{
			GOTOx = 5;
			GOTOy = 6;
		}
	}
	eraseDisplay();

	Xdif = XCalculation(StartX, GOTOx);
	Ydif  = YCalculation(StartY, GOTOy);

	count = 0;
	while(count < Xdif)
	{
		count = count + 1;
		drive(0, distance, 50);
		sleep(300);
		displayCenteredBigTextLine(4,"Location is :");
		displayCenteredBigTextLine(7, "%d, %d", (count)+StartX,StartY);
	}
	whileloop = 0;
	if (GOTOy < StartY)
	{
		//going 4,1
		turn90(-100);
		count = 0;
		while(count < Ydif)
		{
			count = count + 1;
			drive(0, distance, 50);
			sleep(300);
			displayCenteredBigTextLine(4,"Location is :");
			displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count)+StartY);
		}

	}
	else
	{
		//going 5,6
		turn90(100);
		count = 0;
		while(count < Ydif)
		{
			count = count + 1;
			drive(0, distance, 50);
			sleep(300);
			displayCenteredBigTextLine(4,"Location is :");
			displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count)+StartY);
		}
	}
}