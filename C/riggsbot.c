#pragma config(Motor,  port1,           fw1,           tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           fw2,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           bw1,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           bw2,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           fly1,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           fly2,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           lift,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true) {
		if (vexRT[Btn8D]) {
			motor[fw1] = -255;
			motor[fw2] = -255;
			motor[bw1] = -255;
			motor[bw2] = -255;
		}
		else if (vexRT[Btn8U]) {
			motor[fw1] = 255;
			motor[fw2] = 255;
			motor[bw1] = 255;
			motor[bw2] = 255;
		}
		else if (vexRT[Btn8L]) {
			motor[fw1] = 255;
			motor[bw1] = -255;
			motor[fw2] = -255;
			motor[bw2] = 255;
		}
		else if (vexRT[Btn8R]) {
			motor[fw1] = -255;
			motor[bw1] = 255;
			motor[fw2] = 255;
			motor[bw2] = -255;
		}
		else if (vexRT[Btn6U]) {
			motor[fly1] = 255;
			motor[fly2] = 255;
		}
		else if (vexRT[Btn5U]) {
			motor[lift] = 255;
		}
		else {
			motor[fw1] = vexRT[Ch3];
			motor[fw2] = vexRT[Ch2];
			motor[bw1] = vexRT[Ch3];
			motor[bw2] = vexRT[Ch2];
			motor[fly1] = 0;
			motor[fly2] = 0;
			motor[lift] = 0;
		}
	}
}
