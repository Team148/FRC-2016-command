#include "IntakeDown.h"

IntakeDown::IntakeDown()
{
	IntakeArm* m_intakeArm = m_intakeArm->GetInstance();
	Requires(m_intakeArm);
}

// Called just before this Command runs the first time
void IntakeDown::Initialize()
{
	m_startTime = Timer::GetFPGATimestamp();
	IntakeArm::GetInstance()->SetSpeed(0.75);
	m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void IntakeDown::Execute()
{
	std::cout << "down delay IntakeArm" << (Timer::GetFPGATimestamp() - m_startTime) << std::endl;

		if((Timer::GetFPGATimestamp() - m_startTime) >= m_armTime)
		{
			std::cout << "Down Timer Passed" << Timer::GetFPGATimestamp() << std::endl;
			IntakeArm::GetInstance()->SetSpeed(0.0);
			m_isFinished = true;
		}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeDown::IsFinished()
{
	return m_isFinished;
}

// Called once after isFinished returns true
void IntakeDown::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeDown::Interrupted()
{

}
