#ifndef ActionArmDown_H
#define ActionArmDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActionArmDown: public CommandBase
{
public:
	ActionArmDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
