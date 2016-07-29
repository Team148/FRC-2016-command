#ifndef SpecialIntake_H
#define SpecialIntake_H

#include "WPILib.h"

class SpecialIntake: public Command
{
public:
	SpecialIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
