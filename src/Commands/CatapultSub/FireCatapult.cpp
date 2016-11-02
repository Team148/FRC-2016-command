#include <Commands/CatapultSub/FireCatapult.h>

FireCatapult::FireCatapult(bool isLong)
{
	m_isLong = isLong;
	Requires(Catapult::GetInstance());
}

// Called just before this Command runs the first time
void FireCatapult::Initialize()
{
	m_timer = new Timer();
	if(m_isLong)
			m_step1 = Preferences::GetInstance()->GetDouble("CATAPULT_SHOT_LONG_DWELL",0.2);
	else
			m_step1 = Preferences::GetInstance()->GetDouble("CATAPULT_SHOT_SHORT_DWELL",0.4);

	m_startTime = m_timer->GetFPGATimestamp();
	m_finished = 0;

	Catapult::GetInstance()->SetOpen(1);
}

// Called repeatedly when this Command is scheduled to run
void FireCatapult::Execute()
{
//	std::cout<<m_timer->GetFPGATimestamp()<<std::endl;

	if(m_timer->GetFPGATimestamp()-m_startTime > m_step1) //checks to see if time is still good, doesn't open if already open
		m_finished = 1;
}

// Make this return true when this Command no longer needs to run execute()
bool FireCatapult::IsFinished()
{
	return m_finished;
}

// Called once after isFinished returns true
void FireCatapult::End()
{
	m_timer = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireCatapult::Interrupted()
{

}
