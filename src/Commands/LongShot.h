#ifndef LongShot_H
#define LongShot_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Constants/Constants.h"

class LongShot: public CommandBase
{
public:
	LongShot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer* m_timer;
	double m_startTime;
};

#endif
