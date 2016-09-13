#include "JoystickDriveEncoderFeedback.h"

using namespace std;

JoystickDriveEncoderFeedback::JoystickDriveEncoderFeedback()
{
	cout << "info: JoystickDriveEncoderFeedback constructor" << endl;
	Requires(Drivetrain::GetInstance());
}

// Called just before this Command runs the first time
void JoystickDriveEncoderFeedback::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void JoystickDriveEncoderFeedback::Execute()
{
	//read rotation stick
	//read both encoders tick counted since last loop
	//setpoint is always 0
	//error = difference between encoders
	//multiply rotation stick by kP

	//Drivetrain::GetInstance()->Arcade(OperatorInterface::GetInstance()->GetJoystick()->GetRawAxis(2), OperatorInterface::GetInstance()->GetJoystick()->GetRawAxis(1));
	//set current encoder ticks to previous
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickDriveEncoderFeedback::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void JoystickDriveEncoderFeedback::End()
{
	Drivetrain::GetInstance()->Arcade(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickDriveEncoderFeedback::Interrupted()
{
	End();
}
