#include "IntakeUp.h"

IntakeUp::IntakeUp()
{
	IntakeArm* m_intakeArm = m_intakeArm->GetInstance();
	Requires(m_intakeArm);
}

// Called just before this Command runs the first time
void IntakeUp::Initialize()
{
	m_startTime = Timer::GetFPGATimestamp();
	IntakeArm::GetInstance()->SetSpeed(-0.75);
	m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void IntakeUp::Execute()
{
	std::cout << "up delay IntakeArm" << (Timer::GetFPGATimestamp() - m_startTime) << std::endl;

		if((Timer::GetFPGATimestamp() - m_startTime) >= m_armTime)
		{
			std::cout << "Up Timer Passed" << Timer::GetFPGATimestamp() << std::endl;
			IntakeArm::GetInstance()->SetSpeed(0.0);
			m_isFinished = true;
		}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeUp::IsFinished()
{
	return m_isFinished;
}

// Called once after isFinished returns true
void IntakeUp::End()
{
	IntakeArm::GetInstance()->SetSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeUp::Interrupted()
{
	End();
}
