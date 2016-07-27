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

class IntakeArm
{

public:
	IntakeArm();
	virtual~IntakeArm();

	void SetIntakeUp();
	void SetIntakeDown();


	bool IsIntakeUp();
	bool IsIntakeDown();
	bool IsIntakeFloating();


};

#endif // INTAKEARM_H_
