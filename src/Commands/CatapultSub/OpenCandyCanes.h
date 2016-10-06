#ifndef OpenCandyCanes_H
#define OpenCandyCanes_H

#include "WPILib.h"
#include "Subsystems/CandyCane.h"

class OpenCandyCanes: public Command
{
public:
	OpenCandyCanes();
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
