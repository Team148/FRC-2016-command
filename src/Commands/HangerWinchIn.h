#ifndef HangerWinchIn_H
#define HangerWinchIn_H

#include "WPILib.h"

class HangerWinchIn: public Command
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
