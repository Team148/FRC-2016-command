#ifndef FlashlightOn_H
#define FlashlightOn_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlashlightOn: public CommandBase
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
