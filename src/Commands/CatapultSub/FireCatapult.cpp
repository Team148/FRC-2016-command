#include <Commands/CatapultSub/FireCatapult.h>

FireCatapult::FireCatapult(bool IsLong)
{
	m_timer = new Timer();
	Requires(Catapult::GetInstance());

	if(IsLong)
		m_step1 = 0.2; //CATAPULT_LONG_DWELL;
	else
		m_step1 = 0.2; //CATAPULT_SHORT_DWELL;
}

// Called just before this Command runs the first time
void FireCatapult::Initialize()
{
	m_startTime = m_timer->GetFPGATimestamp();
	m_finished = 0;

	Catapult::GetInstance()->SetOpen(1);
}

// Called repeatedly when this Command is scheduled to run
void FireCatapult::Execute()
{
	double m_currentTime = m_timer->GetFPGATimestamp();

	std::cout<<m_currentTime<<std::endl;

	if(m_currentTime-m_startTime > m_step1){ //checks to see if time is still good, doesn't open if already open
		m_finished = 1;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool FireCatapult::IsFinished()
{
	return m_finished;
}

// Called once after isFinished returns true
void FireCatapult::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireCatapult::Interrupted()
{

}
