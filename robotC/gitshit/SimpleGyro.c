

task main()
{
	
	int Angle;
	
	eraseDisplay();  // Clear the display
	displayCenteredTextLine(2,"gyro resetting");
	
	SensorType[S4] = sensorEV3_Gyro; // set sensor to port 4
	
	sleep(1000);
	resetGyro(S4);
	sleep(2000);
	displayCenteredTextLine(2,"Angle =%d",getGyroDegrees(S4));
	sleep(2000);
	
	
	// Turn Robot 360 degrees around, then stop:
	Angle=getGyroDegrees(S4); // Get the starting angle which should be 0
	displayCenteredTextLine(2,"Angle =%d",Angle);
	
	setMotorSync(motorB, motorC, -100, 10); // -100 is forward on first motor and reverse on second one
	displayCenteredTextLine(2,"rotating 360");
	while (abs(Angle) < 360)
	{
		sleep(2);
		Angle=getGyroDegrees(S4);
		displayCenteredBigTextLine(5,"current angle %4d",Angle);
	}
	
	playTone(440,10);
	setMotorSync(motorB, motorC, 0, 0); // stop the motors
	
	sleep(2000);
	
}
