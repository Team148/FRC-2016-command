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
	void SetArmMode(bool setarm);
	void SetStopMode(bool stoparm);


private:
	ActionArm();
	static ActionArm* m_instance;

	Solenoid *arm_solenoid;
	Solenoid *stop_solenoid;
	bool m_setarm = false; // false : in | true : out
	bool m_stoparm = false; // false : in | true : out
};

#endif /* SRC_SUBSYSTEMS_ACTIONARM_ACTIONARM_H_ */
