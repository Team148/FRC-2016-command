#ifndef OpenClamp_H
#define OpenClamp_H

// #include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Clamp.h"
#include "Preferences.h"

class OpenClamp: public Command
{
public:
	OpenClamp(bool IsLong);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer *m_timer;
	double m_startTime;
	bool m_finished;
	bool m_IsLong;
	double m_step1;
};

#endif
