#include "ActionArmDown.h"

ActionArmDown::ActionArmDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	ActionArm* m_actionArm = m_actionArm->GetInstance();
	Requires(m_actionArm);
}

// Called just before this Command runs the first time
void ActionArmDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ActionArmDown::Execute()
{
	m_actionArm->SetArmMode(true);
}

// Make this return true when this Command no longer needs to run execute()
bool ActionArmDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ActionArmDown::End()
{
	m_actionArm->SetArmMode(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActionArmDown::Interrupted()
{
	End();
}
