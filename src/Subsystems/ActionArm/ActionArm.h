/*
 * ActionArm.h
 *
 *  Created on: Jun 30, 2016
 *      Author: justin
 */

#ifndef SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_
#define SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_

#include "ActionStop.h"
#include "BattleAxe.h"

class ActionArm : public ActionStop, public BattleAxe {
public:
	ActionArm();
	virtual ~ActionArm();
};

#endif /* SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_ */
