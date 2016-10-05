#include <Commands/CatapultSub/OpenClampSub.h>

OpenClampSub::OpenClampSub(bool IsLong)
{
	m_timer = new Timer();
	Requires(Clamp::GetInstance());

	if(IsLong)
		m_step1 = 0.2;//CLAMP_OPEN_LONG_DWELL;
	else
		m_step1 = 0.2;// CLAMP_OPEN_SHORT_DWELL;
}

// Called just before this Command runs the first time
void OpenClampSub::Initialize()
{
	m_startTime = m_timer->GetFPGATimestamp();
	m_finished = 0;

	Clamp::GetInstance()->SetOpen(1); //opens clamp

}

// Called repeatedly when this Command is scheduled to run
void OpenClampSub::Execute()
{
	double m_currentTime = m_timer->GetFPGATimestamp();

	if(m_currentTime-m_startTime > m_step1){ //checks to see if time is still good, doesn't open if already open
		m_finished = 1;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool OpenClampSub::IsFinished()
{
	return m_finished;
}

// Called once after isFinished returns true
void OpenClampSub::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenClampSub::Interrupted()
{

}
