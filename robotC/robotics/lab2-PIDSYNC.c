//variables

//function prototype
void moveRobot();
int randomDirection();

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
		randomDirection();
		motorPower = random(100);
		
		if (randompath == 0)
		{
			waitTime = random(300);
			turnRatio = random(-50);
			moveRobot();
			sleep(1000);
		}
		else
		{
			waitTime = random(300);
			turnRatio = random(50);
			moveRobot();
			sleep(1000);
		}
		loops = loops+1;
	}
}

void moveRobot()
{
	int waitTime = 0;
	int turnRatio = 0;
	int motorPower = 100;
	setMotorSyncTime(motorB, motorC, turnRatio, waitTime, motorPower);
	
}

int randomDirection()
{
	int randompath = 0;
	randompath = random(1);
	return 0;
}
