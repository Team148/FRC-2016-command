#ifndef IntakeDown_H
#define IntakeDown_H

#include "WPILib.h"
#include "Subsystems/IntakeArm.h"

class IntakeDown: public Command
{
public:
	IntakeDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	IntakeArm* m_intakeArm;
	bool m_isFinished = 0;
	double m_startTime;
	double m_armTime = 0.75;

};
#endif
