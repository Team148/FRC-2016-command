#ifndef ActionArmUp_H
#define ActionArmUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActionArmUp: public CommandBase
{
public:
	ActionArmUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
