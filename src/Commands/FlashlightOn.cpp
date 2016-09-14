#include "FlashlightOn.h"



FlashlightOn::FlashlightOn()
{
	cout << "info: FlashlightOn constructor" << endl;
	Requires(Flashlight::GetInstance());
}

// Called just before this Command runs the first time
void FlashlightOn::Initialize()
{
	cout << "info: FlashlightOn Initialize" << endl;
}

// Called repeatedly when this Command is scheduled to run
void FlashlightOn::Execute()
{
	cout << "info: FlashlightOn Execute" << endl;
	Flashlight::GetInstance()->TurnOn();

}

// Make this return true when this Command no longer needs to run execute()
bool FlashlightOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FlashlightOn::End()
{
	cout << "info: FlashlightOn End" << endl;
	Flashlight::GetInstance()->TurnOff();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlashlightOn::Interrupted()
{
	End();
}
