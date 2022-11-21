//definitions
#define WAIT 416

//function prototype
void moveRobot(int, int);
int randomDirection();

//main program
task main()
{
	int waitTime = 0;
	int turnRatio = 0;
	int randompath = 0;
	
	randompath = randomDirection();
		
	if (randompath == 0)
		{
			waitTime = WAIT;
			turnRatio = -50;
			moveRobot(waitTime, turnRatio);
			sleep(1000);
		}
	else
		{
			waitTime = WAIT;
			turnRatio = 50;
			moveRobot(waitTime, turnRatio);
			sleep(WAIT);
		}
	
}

void moveRobot(int waitTime, int turnRatio)
{
	
	int motorPower = 100;
	setMotorSyncTime(motorB, motorC, turnRatio, waitTime, motorPower);
	
}

int randomDirection()
{
	int randompath = 0;
	randompath = random(1);
	return(randompath);
}