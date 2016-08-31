#include "LongShot.h"

LongShot::LongShot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Timer m_timer = new Timer();
}

// Called just before this Command runs the first time
void LongShot::Initialize()
{
	m_startTime = m_timer->GetFPGATimestamp();
}

// Called repeatedly when this Command is scheduled to run
void LongShot::Execute()
{


}

// Make this return true when this Command no longer needs to run execute()
bool LongShot::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LongShot::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LongShot::Interrupted()
{

}
