#ifndef ActionArmChevy_H
#define ActionArmChevy_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActionArmChevy: public CommandBase
{
public:
	ActionArmChevy();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
