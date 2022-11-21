void moveRobot(int, int, int)


moveRobot(10,30,100)

void moveRobot(int turnRatio, int waitTime, int motorPower)
{
	setMotorSyncTime(motorB, motorC, turnRatio, waitTime, motorPower);
}