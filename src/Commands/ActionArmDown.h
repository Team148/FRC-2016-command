#ifndef ActionArmDown_H
#define ActionArmDown_H

#include "WPILib.h"

class ActionArmDown: public Command
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
