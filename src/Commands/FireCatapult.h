#ifndef FireCatapult_H
#define FireCatapult_H

#include "../CommandBase.h"
#include "WPILib.h"

class FireCatapult: public CommandBase
{
public:
	FireCatapult();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
