#ifndef INTAKEROLLER_H_
#define INTAKEROLLER_H_


#include "WPILib.h"
#include "Constants/Ports.h"

class IntakeRoller : public Subsystem
{
public:
	static IntakeRoller* GetInstance();
	void SetSpeed(double speed);

private:
	IntakeRoller();
	static IntakeRoller* m_instance;
	CanTalonSRX* RollerMotor;

	double m_speed = 0;

};

#endif // INTAKEROLLER_H_
