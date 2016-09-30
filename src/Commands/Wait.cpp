#include "Wait.h"

Wait::Wait(double time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	m_waittime = time;
}

// Called just before this Command runs the first time
void Wait::Initialize()
{
	m_isFinished = false;
	m_starttime = Timer::GetFPGATimestamp();
}

// Called repeatedly when this Command is scheduled to run
void Wait::Execute()
{
	if(Timer::GetFPGATimestamp() - m_starttime >= m_waittime)
		m_isFinished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool Wait::IsFinished()
{
	return m_isFinished;
}

// Called once after isFinished returns true
void Wait::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Wait::Interrupted()
{
	End();
}
