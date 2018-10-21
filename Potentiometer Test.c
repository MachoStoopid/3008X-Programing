#pragma config(Sensor, in1,    CatapultPotentiometer, sensorPotentiometer)
task main()
{
 while(1==1)
	{
	int x=SensorValue(CatapultPotentiometer);
	writeDebugStreamLine("Potentiomete value is: %d", x); //Prints value of potentiometer
	wait(0.1);
	}


}
