#ifndef INTAKEROLLER_H_
#define INTAKEROLLER_H_


#include "Timer.h"
#include "WPILib.h"

class IntakeRoller
{

public:
	IntakeRoller();
	virtual~IntakeRoller();


	void Intake();
	void Outtake();

	bool IsIntaking();
	bool IsOuttaking();
	bool IsBallSeen();

};

#endif // INTAKEROLLER_H_
