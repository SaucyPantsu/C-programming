//definitions
#define WAIT 416

//function prototype
void moveRobot(int, int, int);

//main program
task main()
{
	int waitTime = 0;
	int turnRatio = 0;
    int loops =0;
	
    moveRobot(2000, 0, 100);
    sleep(2000);
    moveRobot(WAIT*2, 100, 50);
    moveRobot(4000, 0, 50)
    
}

void moveRobot(int waitTime, int turnRatio, int motorPower)
{
	
	setMotorSyncTime(motorB, motorC, turnRatio, waitTime, motorPower);
	
}
