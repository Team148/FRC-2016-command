#ifndef IntakeIn_H
#define IntakeIn_H

#include "WPILib.h"
#include "Subsystems/IntakeRoller.h"

class IntakeIn: public Command
{
public:
	IntakeIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:

};

#endif
