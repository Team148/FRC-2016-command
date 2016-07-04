/*
 * ActionArm.h
 *
 *  Created on: Jun 30, 2016
 *      Author: justin
 */

#ifndef SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_
#define SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_

#include "Timer.h"

class ActionArm {
public:
	ActionArm();
	virtual ~ActionArm();

	//Setters
	void SetUpMode();
	void SetChevyMode();
	void SetPorticullisMode();

	//Getters
	bool InChevyMode();
	bool InPorticullisMode();

private:

};

#endif /* SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_ */
