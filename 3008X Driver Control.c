#pragma config(Sensor, in1,    CatapultPotentiometer, sensorPotentiometer)
#pragma config(Motor,  port1,           frontRightMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           backRightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftCatapult,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightCatapult, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           frontLeftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backLeftMotor, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
		while(1 == 1)
		{
			//Right side of the robot is controlled by the right joystick, Y-axis
			motor[frontRightMotor] = vexRT[Ch2];
			motor[backRightMotor]  = vexRT[Ch2];
			//Left side of the robot is controlled by the left joystick, Y-axis
			motor[frontLeftMotor] = vexRT[Ch3];
			motor[backLeftMotor]  = vexRT[Ch3];


		//If Butn 8R Pressed Catapult Cocks
		if(vexRT[Btn8R] == 1)
		{
			motor[leftCatapult]=127;
			motor[rightCatapult]=127;
		}
		//If Btn8R not pressed catapult doesnt move
		else if(vexRT[Btn8R] == 0)
		{
			motor[leftCatapult]=0;
			motor[rightCatapult]=0;
		}

		}






}
