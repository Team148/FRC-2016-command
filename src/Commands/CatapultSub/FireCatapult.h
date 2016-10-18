#ifndef FireCatapult_H
#define FireCatapult_H


#include "WPILib.h"
#include "Subsystems/Catapult.h"
#include "Preferences.h"

class FireCatapult: public Command
{
public:
	FireCatapult(bool IsLong);
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
	bool m_isLong;
};

#endif
