/*
 * IntakeArm.h
 *
 *  Created on: July 6, 2016
 *      Author: Zach Cody
 */
#ifndef INTAKEARM_H_
#define INTAKEARM_H_


#include "Timer.h"
#include "WPILib.h"
#include "Constants/Ports.h"
#include "CanTalonSRX.h"

class IntakeArm : public Subsystem
{
public:
	static IntakeArm* GetInstance();
	void SetSpeed(double speed);


private:
	IntakeArm();
	static IntakeArm* m_instance;
	CanTalonSRX* ArmMotor;

	double m_speed = 0;

};

#endif // INTAKEARM_H_
