#ifndef OpenClamp_H
#define OpenClamp_H

#include "WPILib.h"

class OpenClamp: public Command
{
public:
	OpenClamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
