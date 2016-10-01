#ifndef BeamBreakIntake_H
#define BeamBreakIntake_H

#include "WPILib.h"
#include "Subsystems/IntakeRoller.h"


class BeamBreakIntake: public Command
{
public:
	BeamBreakIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_isFinished;
	double m_delaystarttime;
	bool m_balldetected;
	double m_afterballdelay = 0.24;

};

#endif
