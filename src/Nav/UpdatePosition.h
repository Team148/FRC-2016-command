#ifndef UpdatePosition_H
#define UpdatePosition_H

#include "WPILib.h"
#include "math.h"

#include "Subsystems/Drivetrain.h"

class UpdatePosition: public Command
{
public:
	UpdatePosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:


};

#endif
