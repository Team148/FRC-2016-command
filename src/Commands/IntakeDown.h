#ifndef IntakeDown_H
#define IntakeDown_H

#include "WPILib.h"

class IntakeDown: public Command
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
