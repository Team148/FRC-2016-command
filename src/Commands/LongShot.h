#ifndef LongShot_H
#define LongShot_H

#include "WPILib.h"
#include "Constants/Constants.h"
#include "Subsystems/Catapult.h"
#include "Subsystems/CandyCane.h"
#include "Subsystems/Clamp.h"

class LongShot: public Command
{
public:
	LongShot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer *m_timer;
	double m_startTime;
	double m_step1;		//open clamp
	double m_step2;		//fire catapult
};

#endif
