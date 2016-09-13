#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H

#include "WPILib.h"
#include "Subsystems/Drivetrain.h"
#include "OperatorInterface.h"


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

};

#endif
