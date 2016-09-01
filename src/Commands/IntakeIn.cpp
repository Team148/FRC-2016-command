#include "IntakeIn.h"

IntakeIn::IntakeIn()
{
	std::cout << "info: IntakeIn constructor" << std::endl;
	IntakeRoller* m_intakeRoller = m_intakeRoller->GetInstance();
	Requires(m_intakeRoller);
}

// Called just before this Command runs the first time
void IntakeIn::Initialize()
{
	std::cout << "info:  IntakeIn Initialize" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void IntakeIn::Execute()
{
	std::cout << "info: IntakeIn Execute" << std::endl;
	m_intakeRoller->SetSpeed(1.0);

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeIn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeIn::End()
{
	std::cout << "info: IntakeIn End" << std::endl;
	m_intakeRoller->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeIn::Interrupted()
{
	End();
}
