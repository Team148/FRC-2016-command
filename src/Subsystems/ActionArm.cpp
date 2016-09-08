/*
 * ActionArm.cpp
 *
 *  Created on: Jun 30, 2016
 *      Author: Justin
 */

#include "ActionArm.h"

ActionArm* ActionArm::m_instance = 0;  						//Global static pointer

ActionArm::ActionArm() : Subsystem("ActionArm") {
	std::cout << "Starting Action Arm" << std::endl;
	arm_solenoid = new Solenoid(0, ACTION_ARM);
	stop_solenoid = new Solenoid(0,ACTION_ARM_STOP);



}

ActionArm* GetInstance() {
	if (m_instance ==  0) {
		m_instance = new ActionArm();
		std::cout << "info: Creating ActionArm Class" << std::endl;
	}
	return m_instance;
}

void ActionArm::SetArmMode(bool setarm) {
	m_setarm = setarm;
	arm_solenoid->Set(m_setarm);
}

void ActionArm::SetStopMode(bool stoparm) {
	m_stoparm = stoparm;
	stop_solenoid->Set(m_stoparm);
}
