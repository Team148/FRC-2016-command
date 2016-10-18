#ifndef CloseCandyCane_H
#define CloseCandyCane_H

#include "WPILib.h"
#include "Preferences.h"

#include "Subsystems/CandyCane.h"


class CloseCandyCane: public Command
{
public:
	CloseCandyCane();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer *m_timer;
	double m_startTime;
	bool m_finished;
	double m_step1;
};

#endif
