#include "ShiftHighGear.h"

using namespace std;

ShiftHighGear::ShiftHighGear()
{
	cout << "info: ShiftHighGear constructor" << endl;
	//Requires(Drivetrain::GetInstance());
}

// Called just before this Command runs the first time
void ShiftHighGear::Initialize()
{
	cout << "info: ShiftHighGear initialize" << endl;
	Drivetrain::GetInstance()->SetGear(0);
}

// Called repeatedly when this Command is scheduled to run
void ShiftHighGear::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftHighGear::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShiftHighGear::End()
{
	cout << "info: ShiftHighGear End" << endl;
	Drivetrain::GetInstance()->SetGear(1);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftHighGear::Interrupted()
{

}
