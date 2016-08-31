#include "ActionArmChevy.h"

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
	m_actionArm->PortcullisMode(true);
	Wait(0.5);
	m_actionArm->ChevyMode(true);
	m_actionArm->PortcullisMode(false);
}

// Make this return true when this Command no longer needs to run execute()
bool ActionArmChevy::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ActionArmChevy::End()
{
	m_actionArm->PortcullisMode(true);
	Wait(0.2);
	m_actionArm->ChevyMode(false);
	m_actionArm->PortcullisMode(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActionArmChevy::Interrupted()
{
	End();
}
