#ifndef LongShot_H
#define LongShot_H

#include "Commands/Command.h"
#include "WPILib.h"

class LongShot: public CommandBase
{
public:
	LongShot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
