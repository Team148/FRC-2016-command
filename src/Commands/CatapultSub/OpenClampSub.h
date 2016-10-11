#ifndef OpenClampSub_H
#define OpenClampSub_H

// #include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Clamp.h"
//#include "Constants/Constants.h"

class OpenClampSub: public Command
{
public:
	OpenClampSub(bool IsLong);
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
