//definitions
#define WAIT 550
#define TEST 5000
#define QUARTER43 100
//function prototype
void drive(long motorRatio,long dist, long power)
{
	setMotorSyncEncoder(motorB, motorC, motorRatio, dist, power);
}
void turn90(long motorRatio,long EncoderCount, long power)
{
	setMotorSyncEncoder(motorB, motorC, motorRatio, EncoderCount, power);

}

//main program
task main()
{
	int loops = 0;
	int distance = QUARTER43;

	while(loops<4)
	{
		long turnDist = distance*4*(loops+1);
		turn90(-50, turnDist, 100);
		sleep(WAIT);
		drive(0, distance*4, 50);
		sleep(3000);
		loops = loops+1;

	}

}
