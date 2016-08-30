#include "HangerWinchIn.h"

HangerWinchIn::HangerWinchIn()
{
	m_hangerWinch->GetInstance();
	m_hangerArm->GetInstance();
	Requires(m_hangerWinch);
	Requires(m_hangerArm);
}

// Called just before this Command runs the first time
void HangerWinchIn::Initialize()
{
	//if HangerArm hasn't deployed, exit
	if(!m_hangerArm->IsDeployed()) {
		std::cout << "error: attempting to winch-in without deploying Hanger Arms" << std::endl;
		End();
	}

}

// Called repeatedly when this Command is scheduled to run
void HangerWinchIn::Execute()
{
	m_hangerWinch->SetSpeed(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool HangerWinchIn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void HangerWinchIn::End()
{
	m_hangerWinch->SetSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HangerWinchIn::Interrupted()
{
	End();
}
