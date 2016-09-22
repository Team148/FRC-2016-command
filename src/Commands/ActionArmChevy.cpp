#include "ActionArmChevy.h"

ActionArmChevy::ActionArmChevy(bool isActionDown)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	m_goingUp = isActionDown;
	Requires(ActionArm::GetInstance());
}

// Called just before this Command runs the first time
void ActionArmChevy::Initialize()
{
	//m_chevyDownTime->Start();
	ActionArm::GetInstance()->SetArmMode(true);
	m_startTime = Timer::GetFPGATimestamp();
}

// Called repeatedly when this Command is scheduled to run
void ActionArmChevy::Execute()
{
//	m_actionArm->SetArmMode(true);
//	Wait(0.5);
//	m_actionArm->SetStopMode(true);
//	m_actionArm->SetArmMode(false);
	if(m_goingUp)
	{
		if((Timer::GetFPGATimestamp() - m_startTime) >= m_chevyDownTime)
		{
			ActionArm::GetInstance()->SetStopMode(true);
			ActionArm::GetInstance()->SetArmMode(false);
			m_isFinished = true;
		}

	}

}

// Make this return true when this Command no longer needs to run execute()
bool ActionArmChevy::IsFinished()
{
	return m_isFinished;
}

// Called once after isFinished returns true
void ActionArmChevy::End()
{
//	m_actionArm->SetArmMode(true);
//	Wait(0.2);
//	m_actionArm->SetStopMode(false);
//	m_actionArm->SetArmMode(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActionArmChevy::Interrupted()
{
	End();
}
