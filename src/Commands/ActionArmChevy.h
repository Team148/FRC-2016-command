#ifndef ActionArmChevy_H
#define ActionArmChevy_H

#include "WPILib.h"
#include "Subsystems/ActionArm.h"


class ActionArmChevy : public Command
{
public:
	ActionArmChevy();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	ActionArm* m_actionArm;
};

#endif
