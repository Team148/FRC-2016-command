#ifndef ToggleClamp_H
#define ToggleClamp_H

#include <Subsystems/Clamp.h>
#include "WPILib.h"

class ToggleClamp: public Command
{
public:
	ToggleClamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
