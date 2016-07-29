#ifndef CloseClamp_H
#define CloseClamp_H

#include "WPILib.h"

class CloseClamp: public Command
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
