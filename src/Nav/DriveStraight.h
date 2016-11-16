#ifndef DriveStraight_H
#define DriveStraight_H


#include "WPILib.h"
#include "Subsystems/Drivetrain.h"
#include "TrapezoidalProfile.h"

class DriveStraight: public Command
{
public:
	DriveStraight(double distance, double ExitVelocity, double DeadBand);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	TrapezoidalProfile *m_profile;
	Timer *m_timer;
	bool m_finished;
	double m_lastTime = 0;
	double m_startPos;
	double m_finalPos;
	double m_ExitVelocity;
	double m_DeadBand;
};

#endif
