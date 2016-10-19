#include "CalibrateGyro.h"

CalibrateGyro::CalibrateGyro()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Drivetrain::GetInstance());
}

// Called just before this Command runs the first time
void CalibrateGyro::Initialize()
{
	Drivetrain::GetInstance()->GetGyro()->Calibrate();
}

// Called repeatedly when this Command is scheduled to run
void CalibrateGyro::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CalibrateGyro::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CalibrateGyro::End()
{
	std::cout<<"GyroCalibrated! @ " <<Drivetrain::GetInstance()->GetGyroAngle() <<" degrees."<<std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CalibrateGyro::Interrupted()
{

}
