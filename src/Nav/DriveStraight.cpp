#include "DriveStraight.h"

DriveStraight::DriveStraight(double distance, double ExitVelocity, double DeadBand)
{
	m_timer = new Timer();
	m_profile = new TrapezoidalProfile(78,144); // units in inches;
	m_finalPos = distance;
	m_ExitVelocity = ExitVelocity;
	m_DeadBand = DeadBand;
	Drivetrain::GetInstance()->SetVelocityMode();
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	m_lastTime = m_timer->GetFPGATimestamp();
	m_startPos = Drivetrain::GetInstance()->GetAvgDistanceInInches();
	m_profile->Update(m_finalPos,0.0,0.0,0.02);	//cheating since finalPos = distance
	m_finalPos += m_startPos;
	m_profile->PrintAccelProfile();

}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{
	double m_Distance = m_finalPos-Drivetrain::GetInstance()->GetAvgDistanceInInches();
	double m_currentVel = Drivetrain::GetInstance()->GetAvgEncSpeed();
	double m_dt = m_timer->GetFPGATimestamp()- m_lastTime;

	m_profile->Update(m_Distance, m_currentVel, m_ExitVelocity, m_dt);

	m_lastTime = m_timer->GetFPGATimestamp();

	if(m_Distance < m_DeadBand)
		m_finished = 1;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return m_finished;
}

// Called once after isFinished returns true
void DriveStraight::End()
{
	Drivetrain::GetInstance()->SetVBusMode();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{

}
