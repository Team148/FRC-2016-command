#ifndef IntakeUp_H
#define IntakeUp_H

#include "WPILib.h"

class IntakeUp: public Command
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
