#pragma config(Motor,  port2,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightWheel,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftWheel,     tmotorVex393_MC29, openLoop)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()// blue left
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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  while (true) {
		motor[rightWheel] = vexRT[Ch2];
		motor[leftWheel] = vexRT[Ch3];
		if (((vexRT[Btn5U] && vexRT[Btn6U]) || vexRT[Btn8U]) && ! (vexRT[Btn8D])) {
			motor[leftLift] = 255;
			motor[rightLift] = 255;
		}
		else if ((vexRT[Btn5U] && vexRT[Btn6U]) || vexRT[Btn8D]) {
			motor[leftLift] = -255;
			motor[rightLift] = -255;
		}
		else if (vexRT[Btn5U]) {
			motor[leftLift] = 255;
			motor[rightLift] = 0;
		}
		else if (vexRT[Btn5D]) {
			motor[leftLift] = -255;
			motor[rightLift] = 0;
		}
		else if (vexRT[Btn6U]) {
			motor[rightLift] = 255;
			motor[leftLift] = 0;
		}
		else if (vexRT[Btn6D]) {
			motor[rightLift] = -255;
			motor[leftLift] = 0;
		}
		else {
			motor[leftLift] = 0;
			motor[rightLift] = 0;
		}
		//flip cap
		if (vexRT[Btn7U]) {
			motor[rightWheel] = 255;
			motor[leftWheel] = 255;
			motor[leftLift] = 255;
			motor[rightLift] = 255;
			delay (1300);
			motor[leftLift] = 0;
			motor[leftLift] = 0;
			motor[rightWheel] = 0;
			motor[leftWheel] = 0;
		}
		//climb on platform
		if (vexRT[Btn7L]) {
			motor[leftLift] = -255;
			motor[rightLift] = -255;
			delay (1000);
			motor[leftLift] = 0;
			motor[rightLift] = 0;
			motor[leftWheel] = 255;
			motor[rightWheel] = 255;
			delay (1200);
			motor[rightWheel] = 0;
			motor[leftWheel] = 0;
		}
	}
}
