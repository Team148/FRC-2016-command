#ifndef DeployHanger_H
#define DeployHanger_H

#include "WPILib.h"
#include "Subsystems/HangerArm.h"

class DeployHanger: public Command
{
public:
	DeployHanger();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	HangerArm* m_hangerArm;
};

#endif
