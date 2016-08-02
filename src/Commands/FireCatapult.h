#ifndef FireCatapult_H
#define FireCatapult_H


#include "WPILib.h"

class FireCatapult: public Command
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
