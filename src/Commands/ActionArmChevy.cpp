#include "Commands/ActionArmChevy.h"

ActionArmChevy::ActionArmChevy(bool isActionDown)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	m_goingDown = isActionDown;
	Requires(ActionArm::GetInstance());
}

// Called just before this Command runs the first time
void ActionArmChevy::Initialize()
{
	//m_chevyDownTime->Start();
	std::cout << "info:  ActionArmChevy Initialize" << std::endl;
	ActionArm::GetInstance()->SetArmMode(true);
	m_startTime = Timer::GetFPGATimestamp();
	m_isFinished = false;

}

// Called repeatedly when this Command is scheduled to run
void ActionArmChevy::Execute()
{

//	m_actionArm->SetArmMode(true);
//	Wait(0.5);
//	m_actionArm->SetStopMode(true);
//	m_actionArm->SetArmMode(false);
	if(m_goingDown)
	{
		std::cout << "down delay" << (Timer::GetFPGATimestamp() - m_startTime) << std::endl;

		if((Timer::GetFPGATimestamp() - m_startTime) >= m_chevyDownTime)
		{
			std::cout << "Down Timer Passed" << Timer::GetFPGATimestamp() << std::endl;
			ActionArm::GetInstance()->SetStopMode(true);
			ActionArm::GetInstance()->SetArmMode(false);
			m_isFinished = true;
		}
	}
	else
	{
		std::cout << "up delay" << (Timer::GetFPGATimestamp() - m_startTime) << std::endl;

		if((Timer::GetFPGATimestamp() - m_startTime) >= m_chevyUpTime)
		{
			std::cout << "Up Timer Passed" << Timer::GetFPGATimestamp() << std::endl;
			ActionArm::GetInstance()->SetStopMode(false);
			ActionArm::GetInstance()->SetArmMode(false);
			m_isFinished = true;
		}
	}


}

// Make this return true when this Command no longer needs to run execute()
bool ActionArmChevy::IsFinished()
{
	std::cout << "info:  ActionArmChevy isFinished" << m_goingDown << std::endl;
	return m_isFinished;
}

// Called once after isFinished returns true
void ActionArmChevy::End()
{
	ActionArm::GetInstance()->SetArmMode(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActionArmChevy::Interrupted()
{
	End();
}
