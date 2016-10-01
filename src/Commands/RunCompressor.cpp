#include "RunCompressor.h"

RunCompressor::RunCompressor()
{
	Requires(Pneumatic::GetInstance());
}

// Called just before this Command runs the first time
void RunCompressor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunCompressor::Execute()
{
	//check if the pressure switch has flipped and either turn the relay on or off.
	//std::cout << "info: RunCompressor Execute - PressureSwtich:" <<  Pneumatic::GetInstance()->m_comp->GetPressureSwitchValue() << std::endl;
	if(Pneumatic::GetInstance()->m_comp->GetPressureSwitchValue()) {Pneumatic::GetInstance()->SetCompressor(false);}
			else {Pneumatic::GetInstance()->SetCompressor(true);}

}

// Make this return true when this Command no longer needs to run execute()
bool RunCompressor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RunCompressor::End()
{
	//turn relay off
	Pneumatic::GetInstance()->SetCompressor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunCompressor::Interrupted()
{
	End();
}
