#include "GyroTurn.h"

GyroTurn::GyroTurn(float degrees)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Drivetrain::GetInstance());

	m_setpoint = degrees;
}

// Called just before this Command runs the first time
void GyroTurn::Initialize()
{
	//make sure we're stopped
	Drivetrain::GetInstance()->Arcade(0,0);
}

// Called repeatedly when this Command is scheduled to run
void GyroTurn::Execute()
{
	m_error = m_setpoint - Drivetrain::GetInstance()->GetGyroAngle();

	double output = m_error * m_kp;

	Drivetrain::GetInstance()->Arcade(0,output);
	m_preverror = m_error;
}

// Make this return true when this Command no longer needs to run execute()
bool GyroTurn::IsFinished()
{
	if(abs(m_error) < 1)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void GyroTurn::End()
{
	Drivetrain::GetInstance()->Arcade(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroTurn::Interrupted()
{
	Drivetrain::GetInstance()->Arcade(0,0);
}
