#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick()
{
	std::cout << "info: DriveWithJoystick constructor" << std::endl;
	Requires(Drivetrain::GetInstance());

}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{

	Drivetrain::GetInstance()->Arcade(-OperatorInterface::GetInstance()->GetJoystick()->GetRawAxis(1), OperatorInterface::GetInstance()->GetJoystick()->GetRawAxis(2));

}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End()
{
	Drivetrain::GetInstance()->Arcade(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted()
{
	End();
}
