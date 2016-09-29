#ifndef ActionArmDown_H
#define ActionArmDown_H

#include "WPILib.h"
#include "Subsystems/ActionArm.h"

class ActionArmDown: public Command
{
public:
	ActionArmDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	ActionArm* m_actionArm;
};


#endif
