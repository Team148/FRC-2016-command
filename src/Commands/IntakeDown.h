#ifndef IntakeDown_H
#define IntakeDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeDown: public CommandBase
{
public:
	IntakeDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
