#include "IntakeOut.h"

IntakeOut::IntakeOut()
{
	//IntakeRoller* m_intakeRoller = m_intakeRoller->GetInstance();
	m_intakeRoller = IntakeRoller::GetInstance();
	Requires(m_intakeRoller);
}

// Called just before this Command runs the first time
void IntakeOut::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeOut::Execute()
{
	m_intakeRoller->SetSpeed(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOut::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeOut::End()
{
	m_intakeRoller->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOut::Interrupted()
{
	End();
}
