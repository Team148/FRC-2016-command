#ifndef ActionArmChevy_H
#define ActionArmChevy_H

#include "WPILib.h"
#include "Subsystems/ActionArm.h"


class ActionArmChevy : public Command
{
public:
	ActionArmChevy(bool isActionDown);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	ActionArm* m_actionArm;

	//Timer* m_chevyDownTime;
	Timer* m_chevyUpTime;

	bool m_goingUp;
	bool m_isFinished;
	double m_startTime;
	double m_chevyDownTime = 0.6;

};

#endif
