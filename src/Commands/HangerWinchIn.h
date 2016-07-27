#ifndef HangerWinchIn_H
#define HangerWinchIn_H

#include "../CommandBase.h"
#include "WPILib.h"

class HangerWinchIn: public CommandBase
{
public:
	HangerWinchIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
