#ifndef Drive_H
#define Drive_H

#include "WPILib.h"

class Drive: public Command
{
public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
