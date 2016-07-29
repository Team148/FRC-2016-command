#ifndef ResetCatapult_H
#define ResetCatapult_H

#include "WPILib.h"

class ResetCatapult: public Command
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
