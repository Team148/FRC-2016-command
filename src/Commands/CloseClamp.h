#ifndef CloseClamp_H
#define CloseClamp_H

#include "../CommandBase.h"
#include "WPILib.h"

class CloseClamp: public CommandBase
{
public:
	CloseClamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
