//definitions
#define WAIT 416

//function prototype
void moveRobot(int, int);

//main program
task main()
{
	int waitTime = 0;
	int turnRatio = 0;
    int loops =0;
	
    while(loops <4)
    {
        waitTime = WAIT;
        turnRatio = -50;
        moveRobot(waitTime, turnRatio);
        sleep(1000);
        loops = loops + 1;
    }

}

void moveRobot(int waitTime, int turnRatio)
{
	
	int motorPower = 100;
	setMotorSyncTime(motorB, motorC, turnRatio, waitTime, motorPower);
	
}






