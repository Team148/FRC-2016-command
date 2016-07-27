#ifndef DeployHanger_H
#define DeployHanger_H

#include "../CommandBase.h"
#include "WPILib.h"

class DeployHanger: public CommandBase
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
