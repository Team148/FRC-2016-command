#include "ResetCatapult.h"

ResetCatapult::ResetCatapult()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetCatapult::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ResetCatapult::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetCatapult::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ResetCatapult::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetCatapult::Interrupted()
{

}
