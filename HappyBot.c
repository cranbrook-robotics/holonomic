#pragma config(Sensor, in1,    gyroPort,       sensorGyro)
#pragma config(Motor,  port2,           mDriveBR,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           mDriveBL,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           mDriveFL,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           mDriveFR,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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


#include <CKHolonomic.h>


HolonomicBase base;

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

  tMotor ports[] = {mDriveBR, mDriveFR, mDriveFL, mDriveBL};
  InitHolonomicBase(base, ports, 4);
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

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
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
  // User control code here, inside the loop

  while (true)
  {
		//int joyL = vexRT[Ch3];
		//int joyR = vexRT[Ch2];
		//motor[mDriveBL] = motor[mDriveFL] = joyL;
		//motor[mDriveBR] = motor[mDriveFR] = joyR;
  	float robotHeading = degreesToRadians( (SensorValue[gyroPort] / 10.0) * 9/7 );
  	//writeDebugStreamLine("%.2f", robotHeading);
  	setDriveXYRFieldBased(base, joystick(ChJoyLX), joystick(ChJoyLY), joystick(ChJoyRX), robotHeading);
  	delay(30);
  }
}
