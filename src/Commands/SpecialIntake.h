#ifndef SpecialIntake_H
#define SpecialIntake_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpecialIntake: public CommandBase
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
