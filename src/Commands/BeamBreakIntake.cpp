#include "BeamBreakIntake.h"

//TODO: test BeamBreakIntake
BeamBreakIntake::BeamBreakIntake()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(IntakeRoller::GetInstance());
}

// Called just before this Command runs the first time
void BeamBreakIntake::Initialize()
{
	IntakeRoller::GetInstance()->SetSpeed(1.0);
	m_isFinished = false;
	m_balldetected = false;
}

// Called repeatedly when this Command is scheduled to run
void BeamBreakIntake::Execute()
{

	if(!m_balldetected)
	{
		if(IntakeRoller::GetInstance()->IsBeamBroke())
		{
			m_delaystarttime = Timer::GetFPGATimestamp();
			m_balldetected = true;
		}
	}
	else
	{
		//delay after the ball is detected
		if(Timer::GetFPGATimestamp() - m_delaystarttime >= m_afterballdelay)
		{
			//double check the ball is still there.
			if(IntakeRoller::GetInstance()->IsBeamBroke())
			{
				m_isFinished = true;
				IntakeRoller::GetInstance()->SetSpeed(0.0);
			}
			else
				m_balldetected = false;

		}

	}

}

// Make this return true when this Command no longer needs to run execute()
bool BeamBreakIntake::IsFinished()
{
	return m_isFinished;
}

// Called once after isFinished returns true
void BeamBreakIntake::End()
{
	IntakeRoller::GetInstance()->SetSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BeamBreakIntake::Interrupted()
{
	End();
}
