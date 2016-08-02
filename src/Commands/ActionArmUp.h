#ifndef ActionArmUp_H
#define ActionArmUp_H

#include "WPILib.h"

class ActionArmUp : public Command
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
