/*
 * ActionArm.h
 *
 *  Created on: Jun 30, 2016
 *      Author: justin
 */

#ifndef SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_
#define SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_

#include "WPILib.h"
#include "Constants/Ports.h"

class ActionArm : public Subsystem {
public:
	static ActionArm* GetInstance();
	void PortcullisMode(bool portcullis);
	void ActionArm::ChevyMode(bool chevy);


private:
	ActionArm();
	static ActionArm* m_instance;

	Solenoid *arm_solenoid;
	Solenoid *stop_solenoid;
	bool m_portcullis = false;
	bool m_chevy = false;
};

#endif /* SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_ */
