#include "ResetCatapult.h"


ResetCatapult::ResetCatapult(){
	Requires(Catapult::GetInstance());
	Requires(Clamp::GetInstance());
	Requires(CandyCane::GetInstance());
}

// Called just before this Command runs the first time
void ResetCatapult::Initialize(){
	m_finished = 0;
	Catapult::GetInstance()->SetState(0);
	CandyCane::GetInstance()->SetState(0);
	m_finished = 1;
}

// Called repeatedly when this Command is scheduled to run
void ResetCatapult::Execute(){

}

// Make this return true when this Command no longer needs to run execute()
bool ResetCatapult::IsFinished(){
	return m_finished;
}

// Called once after isFinished returns true
void ResetCatapult::End(){

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetCatapult::Interrupted()
{

}
