#ifndef ResetPosition_H
#define ResetPosition_H

#include "WPILib.h"

#include "Subsystems/Drivetrain.h"

class ResetPosition: public Command
{
public:
	ResetPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
