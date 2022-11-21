#define WAIT 800

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

	setMotorSync(motorB, motorC, -100, 30);

	while (abs(getGyroDegrees(S4))<80)
	{
		sleep(1);
		Angle=getGyroDegrees(S4);
	}

	playTone(440,10);
	setMotorSync(motorB, motorC, 0, 0); // stop the motors
	wait1Msec(1000);      // Allow sensor to settle
}

void turnNeg90()
{
	int Angle;

	wait1Msec(1000);
	resetGyro(S4);
	wait1Msec(1000);

	setMotorSync(motorB, motorC, 100, 30);

	while (abs(getGyroDegrees(S4))<80)
	{
		sleep(1);
		Angle=getGyroDegrees(S4);
	}

	playTone(440,10);
	setMotorSync(motorB, motorC, 0, 0); // stop the motors
	wait1Msec(1000);      // Allow sensor to settle
}

task main()
{
	int count = 0;
	int StartX = 1;
	int StartY = 4;
	int GOTOx;
	int GOTOy;
	SensorType[S4] = sensorEV3_Gyro; // set sensor to port 4
	SensorType[S3] = sensorEV3_Color;
	long redVal =0;
	long greenVal = 0;
	long blueVal = 0;
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

	Xdif = GOTOx - StartX ;
	Ydif  = GOTOy - StartY;
	count = 0;
	while(count < Xdif)
		{
			whileloop = 0;
			displayCenteredBigTextLine(4,"Location is:");
			displayCenteredBigTextLine(7, "%d, %d", ((count) + StartX), StartY);
			drive(0, distance*2, 60);
			sleep(WAIT/4);
			getColorRGB(S3, redVal, greenVal, blueVal);
			while(blueVal < 15)
			{
				if(whileloop == 0)
				{
					drive(0, distance, 60);
					sleep(WAIT/4);
					getColorRGB(S3, redVal, greenVal, blueVal);
					whileloop =1;
					count = count +1;
					displayCenteredBigTextLine(4,"Location is:");
					displayCenteredBigTextLine(7, "%d, %d", ((count) + StartX), StartY);
				}
				else
				{
					drive(0, distance*4, 60);
					sleep(WAIT/4);
					getColorRGB(S3, redVal, greenVal, blueVal);
					displayCenteredBigTextLine(4,"Location is:");
					displayCenteredBigTextLine(7, "%d, %d", ((count) + StartX), StartY);
				}
			}

		}
		whileloop = 0;
			if (GOTOy < StartY)
			{
				//going 4,1
				turn90();
				count = Ydif;
				while((-count) > 0)
					{
						displayCenteredBigTextLine(4,"Location is :");
						displayCenteredBigTextLine(7, "%d, %d", GOTOx,(-count)+StartY);
						whileloop = 0;
						drive(0, distance, 60);
						sleep(WAIT/4);
						getColorRGB(S3, redVal, greenVal, blueVal);
						while(blueVal < 15)
						{
							if(whileloop == 0)
							{
								count = count - 1;
								drive(0, distance, 60);
								sleep(200);
								getColorRGB(S3, redVal, greenVal, blueVal);
								whileloop =1;
								displayCenteredBigTextLine(4,"Location is :");
								displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count)+StartY);
							}
							else
							{
								drive(0, distance*4, 60);
								sleep(WAIT*2);
								getColorRGB(S3, redVal, greenVal, blueVal);
								displayCenteredBigTextLine(4,"Location is :");
						    displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count)+StartY);
							}
						}


					}
				}
			else
			{
				//going 5,6
				turnNeg90();
				count = 0;
				while(count < Ydif)
					{
						displayCenteredBigTextLine(4,"Location is:");
						displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count)+StartY);
						whileloop = 0;
						drive(0, distance, 60);
						sleep(WAIT/4);
						getColorRGB(S3, redVal, greenVal, blueVal);
						while(blueVal < 15)
						{
							if(whileloop == 0)
							{
								count = count + 1;
								drive(0, distance, 60);
								sleep(200);
								getColorRGB(S3, redVal, greenVal, blueVal);
								whileloop = 1;
								displayCenteredBigTextLine(4,"Location is:");
								displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count)+StartY);
							}
							else
							{
								drive(0, distance*4, 60);
								sleep(WAIT*2);
								getColorRGB(S3, redVal, greenVal, blueVal);
								displayCenteredBigTextLine(4,"Location is:");
								displayCenteredBigTextLine(7, "%d, %d", GOTOx,(count)+StartY);
							}
						}



}
}
}
