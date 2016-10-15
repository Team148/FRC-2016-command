#include "ToggleClamp.h"

ToggleClamp::ToggleClamp()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Clamp::GetInstance());
}

// Called just before this Command runs the first time
void ToggleClamp::Initialize()
{
	if(Clamp::GetInstance()->GetState())
	{
		Clamp::GetInstance()->SetOpen(false);
	}
	else
	{
		Clamp::GetInstance()->SetOpen(true);
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleClamp::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleClamp::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleClamp::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleClamp::Interrupted()
{

}
