#ifndef DeployHanger_H
#define DeployHanger_H

#include "WPILib.h"

class DeployHanger: public Command
{
public:
	DeployHanger();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
