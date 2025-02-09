#include "WPILib.h" 
RobotDrive drivetrain(1, 2); 
Joystick leftStick(1); 
Joystick rightStick(2); 
class RobotDemo : public SimpleRobot 
{ 
 RobotDemo(void) 
 { 
 GetWatchdog().SetEnabled(false); 
 } 
 void Autonomous(void) 
 { 
 for (int i = 0; i < 4; i++) 
 { 
 drivetrain.Drive(0.5, 0.0); // drive 50% forward, 0% turn 
 Wait(2.0); // wait 2 seconds 
 drivetrain.Drive(0.0, 0.75); // drive 0% forward and 75% turn 
 Wait(0.75); // turn for almost a second 
 } 
 drivetrain.Drive(0.0, 0.0); // stop the robot 
 } 
 void OperatorControl(void) 
 { 
 while (1) // loop forever 
 { 
 drivetrain.Tank(leftStick, rightStick); // drive with the joystick 
 Wait(0.005); 
 } 
 } 
}; 
START_ROBOT_CLASS(RobotDemo);