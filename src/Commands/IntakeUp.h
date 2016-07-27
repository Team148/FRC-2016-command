#ifndef IntakeUp_H
#define IntakeUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeUp: public CommandBase
{
public:
	IntakeUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
