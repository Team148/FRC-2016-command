#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_

#include "Timer.h"
#include "WPILib.h"

class Drivetrain
{

public:
	Drivetrain();
	virtual~Drivetrain();

	void setGear();
	void TeleopDrive();
	void AutoDrive();

	bool IsHighGear();
	bool IsTeleopDrive();
};

#endif //DRIVETRAIN_H_
