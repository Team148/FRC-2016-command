#include <Commands/CatapultSub/CloseCandyCane.h>

CloseCandyCane::CloseCandyCane()
{
	m_timer = new Timer();
	Requires(CandyCane::GetInstance());

	m_step1 = 0.2;

}

// Called just before this Command runs the first time
void CloseCandyCane::Initialize()
{
	m_startTime = m_timer->GetFPGATimestamp();
	m_finished = 0;

	CandyCane::GetInstance()->SetOpen(1);
}

// Called repeatedly when this Command is scheduled to run
void CloseCandyCane::Execute()
{
	double m_currentTime = m_timer->GetFPGATimestamp();

	std::cout<<m_currentTime<<std::endl;

	if(m_currentTime-m_startTime > m_step1){ //checks to see if time is still good, doesn't open if already open
		m_finished = 1;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CloseCandyCane::IsFinished()
{
	return m_finished;
}

// Called once after isFinished returns true
void CloseCandyCane::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseCandyCane::Interrupted()
{

}
