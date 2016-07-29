#ifndef FlashlightOn_H
#define FlashlightOn_H

#include "WPILib.h"

class FlashlightOn: public Command
{
public:
	FlashlightOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
