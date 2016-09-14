#include "Commands/ActionArmChevy.h"

ActionArmChevy::ActionArmChevy()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ActionArmChevy::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ActionArmChevy::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ActionArmChevy::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ActionArmChevy::End()
{


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActionArmChevy::Interrupted()
{
	End();
}
