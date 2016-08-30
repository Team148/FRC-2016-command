#include "DeployHanger.h"

DeployHanger::DeployHanger()
{
	m_hangerArm->GetInstance();
	Requires(m_hangerArm);
}

// Called just before this Command runs the first time
void DeployHanger::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DeployHanger::Execute()
{
	m_hangerArm->Deploy();
}

// Make this return true when this Command no longer needs to run execute()
bool DeployHanger::IsFinished()
{
	if(m_hangerArm->IsDeployed())
		return true;
	else
	return false;
}

// Called once after isFinished returns true
void DeployHanger::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeployHanger::Interrupted()
{
	End();
}
