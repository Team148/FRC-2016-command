#ifndef INTAKEROLLER_H_
#define INTAKEROLLER_H_


#include "WPILib.h"
#include "Constants/Ports.h"

class IntakeRoller : public Subsystem
{

public:
	IntakeRoller* GetInstance();
	void SetRollerSpeed(double speed);


private:
	IntakeRoller();
	IntakeRoller* m_instance;
	double m_speed = 0.0;
	CanTalonSRX* m_rollerMotor;

};

#endif // INTAKEROLLER_H_
