#ifndef ShiftHighGear_H
#define ShiftHighGear_H

#include "WPILib.h"
#include "Subsystems/Drivetrain.h"

//TODO: TEST ShiftHighGear Command

class ShiftHighGear: public Command
{
public:
	ShiftHighGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
