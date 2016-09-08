#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include "WPILib.h"

class DriveWithJoystick: public Command
{
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Drivetrain* m_drivetrain;
};

#endif
