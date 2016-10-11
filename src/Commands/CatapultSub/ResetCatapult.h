#ifndef ResetCatapult_H
#define ResetCatapult_H

#include "WPILib.h"
#include "Subsystems/Catapult.h"
#include "Subsystems/CandyCane.h"

class ResetCatapult: public Command
{
public:
	ResetCatapult();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_finished;
};

#endif
