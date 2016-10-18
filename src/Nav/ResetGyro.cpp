#include "ResetGyro.h"

ResetGyro::ResetGyro()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Drivetrain::GetInstance());
}

// Called just before this Command runs the first time
void ResetGyro::Initialize()
{
	Drivetrain::GetInstance()->GetGyro()->Reset();
}

// Called repeatedly when this Command is scheduled to run
void ResetGyro::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetGyro::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetGyro::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetGyro::Interrupted()
{

}
