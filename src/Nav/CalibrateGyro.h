#ifndef CalibrateGyro_H
#define CalibrateGyro_H

#include "WPILib.h"

#include "Subsystems/Drivetrain.h"

class CalibrateGyro: public Command
{
public:
	CalibrateGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
