#ifndef JoystickDriveEncoderFeedback_H
#define JoystickDriveEncoderFeedback_H


#include "WPILib.h"
#include "Subsystems/Drivetrain.h"
#include "OperatorInterface.h"

class JoystickDriveEncoderFeedback: public Command
{
public:
	JoystickDriveEncoderFeedback();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_prevLEncoderCount;
	double m_prevREncoderCount;
	double m_prevError;

	double m_kd;
};

#endif
