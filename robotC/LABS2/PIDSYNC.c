//variables

//function prototype
int moveRobot(int, int, int);
int randomDirection(int);

//main program
task main()
{
	int waitTime = 0;
	int turnRatio = 0;
	int motorPower = 100;
	int randompath = 0;
	int loops = 0;
	
	while (loops < 10)
	{
		randompath = randomDirection(randompath);
		if (randompath == 0)
		{
			waitTime = 3000;
			turnRatio = -50;
			moveRobot(turnRatio, waitTime, 100);
			sleep(1000);
		}
		else
		{
			waitTime = 3000;
			turnRatio = 50;
			moveRobot(turnRatio, waitTime, 100);
			sleep(1000);
		}
		loops = loops+1;
	}
}

int moveRobot(int turnRatio, int waitTime,int motorPower)
{
	setMotorSyncTime(motorB, motorC, turnRatio, waitTime, motorPower);
	return(0);	
}

int randomDirection(int randompath)
{
	int randompath1 = 0;
	randompath1 = random(1);
	return randompath1;
}
