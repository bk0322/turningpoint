#pragma config(Motor,  port2,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightWheel,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftWheel,     tmotorVex393_MC29, openLoop)

task main()
{
	motor[rightWheel] = 255;
	motor[leftWheel] = 255;
	delay (1800);
	motor[rightWheel] = -255;
	motor[leftWheel] = -255;
	delay (1000);
	motor[rightWheel] = -255;
	motor[leftWheel] = 255;
	delay(800);
	motor[leftWheel] = 255;
	motor[rightWheel] = 255;
	delay (750);
	motor[rightWheel] = 0;
	motor[leftWheel] = 0;
	motor[leftLift] = -255;
	motor[rightLift] = -255;
	delay (1000);
	motor[leftLift] = 0;
	motor[rightLift] = 0;
	motor[leftWheel] = 255;
	motor[rightWheel] = 255;
	delay (1500);
	motor[rightWheel] = 0;
	motor[leftWheel] = 0;
}
