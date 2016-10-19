#include "ResetPosition.h"

ResetPosition::ResetPosition()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetPosition::Initialize()
{
	Drivetrain::GetInstance()->SetPositionX(0.0);
	Drivetrain::GetInstance()->SetPositionY(0.0);
}

// Called repeatedly when this Command is scheduled to run
void ResetPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetPosition::End()
{
	std::cout<<"Drivetrain Position has reset to x:"
			<<Drivetrain::GetInstance()->GetPositionX()<<" y:"
			<<Drivetrain::GetInstance()->GetPositionY()<<std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetPosition::Interrupted()
{

}
