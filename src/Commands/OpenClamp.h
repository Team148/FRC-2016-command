#ifndef OpenClamp_H
#define OpenClamp_H

#include "../CommandBase.h"
#include "WPILib.h"

class OpenClamp: public CommandBase
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
