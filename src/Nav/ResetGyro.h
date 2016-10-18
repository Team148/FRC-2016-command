#ifndef ResetGyro_H
#define ResetGyro_H

#include "WPILib.h"

#include "Subsystems/Drivetrain.h"

class ResetGyro: public Command
{
public:
	ResetGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
