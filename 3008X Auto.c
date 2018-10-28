#pragma config(Sensor, in1,    CatapultPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in2,    FlipperPotentiometer, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftLift,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightLift,      sensorQuadEncoder)
#pragma config(Motor,  port1,           frontRightMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           backRightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftCatapult,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightCatapult, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Flipper,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           BallBoy,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           frontLeftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backLeftMotor, tmotorVex393_HBridge, openLoop)

void moveforward()
{
	//Moves robot forward for 1 second
	motor(frontLeftMotor) = 127;
	motor(backLeftMotor) = 127
	motor(frontRightMotor = 127;
	motor(backRightMotor) = 127;
	wait(1000)//Run for 1 second
}

void movebackward()
{
	//Moves robot backward for 1 second
	motor(frontLeftMotor) = -127;
	motor(backLeftMotor) = -127
	motor(frontRightMotor = -127;
	motor(backRightMotor) = -127;
	wait(1000)//Run for 1 second
}

void leftturn()
{
	//Moves right motors forward left motors backward
	motor(frontLeftMotor) = -127;
	motor(backLeftMotor) = -127
	motor(frontRightMotor = 127;
	motor(backRightMotor) = 127;
	wait(1000)//Run for 1 second
}

void rightturn()
{
	//Moves left motors forward right motors backward
	motor(frontLeftMotor) = 127;
	motor(backLeftMotor) = 127
	motor(frontRightMotor = -127;
	motor(backRightMotor) = -127;
	wait(1000)//Run for 1 second
}

void catapultarm(int potentiometeroutput)
//Checks the value of the potentiometer to be put into the task
{
	//If catapult is not cocked start motors
	if(SensorValue[potentiometeroutput] > 1750)
	{
		motor[leftCatapult] = 127;
		motor[rightCatapult] = 127;
	}
	//If catapult is cocked stop motors
	else
	{
		motor[leftCatapult] = 0;
		motor[rightCatapult] = 0;
 	}
}

void intakeon()
{
	//Turns intake on going inward
	motor[BallBoy] = 127;
}

void shooterfire()
{
	//Fires the catapult
	motor[leftCatapult] = 127;
	motor[rightCatapult] = 127;
	wait(250) //Run for 0.25 sec
}

void liftup()
{
	//Turns the lift on going upwards
	motor[leftLift] = 127;
	motor[rightLift] = 127;
	wait(250) //Run for 0.25 sec
}

void liftdown()
{
	motor[leftLift] = -127;
	motor[rightLift] = -127;
	wait(250) //Run for 0.25 sec
}

task main()
{

	intakeon();

	movebackward();

	liftup();

	liftdown();

	moveforward();

	shooterfire();

}
