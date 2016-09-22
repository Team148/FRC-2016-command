#include "ActionArmDown.h"

ActionArmDown::ActionArmDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
<<<<<<< HEAD

	Requires(ActionArm::GetInstance());
=======
	ActionArm* m_actionArm = m_actionArm->GetInstance();
	Requires(m_actionArm);
>>>>>>> refs/remotes/origin/zach-actionarms
}

// Called just before this Command runs the first time
void ActionArmDown::Initialize()
{
	std::cout<<"Setting Action Arm Objects"<< std::endl;
	ActionArm::GetInstance()->SetStopMode(false);
	ActionArm::GetInstance()->SetArmMode(true);
}

// Called repeatedly when this Command is scheduled to run
void ActionArmDown::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ActionArmDown::IsFinished()
{

	return false;
}

// Called once after isFinished returns true
void ActionArmDown::End()
{
<<<<<<< HEAD
	ActionArm::GetInstance()->SetArmMode(false);
=======

>>>>>>> refs/remotes/origin/zach-actionarms
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActionArmDown::Interrupted()
{
	End();
}
