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
	int m_prevLEncoderCount;
	int m_prevREncoderCount;
	int m_prevError;
};

#endif
