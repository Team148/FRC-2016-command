#include "JoystickDriveEncoderFeedback.h"

using namespace std;

JoystickDriveEncoderFeedback::JoystickDriveEncoderFeedback()
{
	cout << "info: JoystickDriveEncoderFeedback constructor" << endl;
	Requires(Drivetrain::GetInstance());
}

// Called just before this Command runs the first time
void JoystickDriveEncoderFeedback::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void JoystickDriveEncoderFeedback::Execute()
{
	float rotatestick = OperatorInterface::GetInstance()->GetJoystick()->GetRawAxis(2);	//read rotation stick

	double rdistance = Drivetrain::GetInstance()->GetREncoder()->GetDistance() - m_prevREncoderCount;//read both encoders tick counted since last loop
	double ldistance = Drivetrain::GetInstance()->GetLEncoder()->GetDistance() - m_prevLEncoderCount;
	double error;

	if(rotatestick == 0) {
		//setpoint is always 0
		//error = difference between encoders
		double error = rdistance - ldistance;
		//multiply rotation stick by kP
		double output = error * m_kp;
		rotatestick = output; // not sure about this
	}

	Drivetrain::GetInstance()->Arcade(OperatorInterface::GetInstance()->GetJoystick()->GetRawAxis(1), rotatestick);

	//set current encoder ticks to previous
	m_prevLEncoderCount = ldistance;
	m_prevREncoderCount = rdistance;
	m_prevError = error;
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickDriveEncoderFeedback::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void JoystickDriveEncoderFeedback::End()
{
	Drivetrain::GetInstance()->Arcade(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickDriveEncoderFeedback::Interrupted()
{
	End();
}
