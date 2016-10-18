#include <Commands/CatapultSub/OpenClamp.h>

OpenClamp::OpenClamp(bool IsLong)
{
	m_IsLong = IsLong;

	Requires(Clamp::GetInstance());


}

// Called just before this Command runs the first time
void OpenClamp::Initialize()
{
	m_timer = new Timer();
	m_startTime = m_timer->GetFPGATimestamp();
	if(m_IsLong)
		m_step1 = Preferences::GetInstance()->GetDouble("CATAPULT_CLAMP_LONG_DWELL",0.2);
	else
		m_step1 = Preferences::GetInstance()->GetDouble("CATAPULT_CLAMP_SHORT_DWELL",0.1);
	m_finished = 0;

	Clamp::GetInstance()->SetOpen(1); //opens clamp

}

// Called repeatedly when this Command is scheduled to run
void OpenClamp::Execute()
{
	double m_currentTime = m_timer->GetFPGATimestamp();

	if(m_currentTime-m_startTime > m_step1){ //checks to see if time is still good, doesn't open if already open
		m_finished = 1;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool OpenClamp::IsFinished()
{
	return m_finished;
}

// Called once after isFinished returns true
void OpenClamp::End()
{
	m_timer = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenClamp::Interrupted()
{

}
