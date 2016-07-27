#ifndef ResetCatapult_H
#define ResetCatapult_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetCatapult: public CommandBase
{
public:
	ResetCatapult();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
