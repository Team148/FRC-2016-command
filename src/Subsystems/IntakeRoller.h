#ifndef INTAKEROLLER_H_
#define INTAKEROLLER_H_


#include "WPILib.h"
#include "Constants/Ports.h"

class IntakeRoller : public Subsystem
{
public:
	static IntakeRoller* GetInstance();
	void SetSpeed(double speed);
	bool IsBeamBroke();

private:
	IntakeRoller();
	static IntakeRoller *m_instance;
	CanTalonSRX *m_RollerMotor;
	AnalogInput* m_BeamBreak;


	double m_speed = 0;


};

#endif // INTAKEROLLER_H_
