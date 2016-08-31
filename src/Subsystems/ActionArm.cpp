/*
 * ActionArm.cpp
 *
 *  Created on: Jun 30, 2016
 *      Author: Justin
 */

#include "ActionArm.h"

ActionArm* ActionArm::m_instance = 0;  						//Global static pointer

ActionArm::ActionArm() : Subsystem("ActionArm") {
	arm_solenoid = new Solenoid(0, ACTION_ARM);
	stop_solenoid = new Solenoid(0,ACTION_ARM_STOP);



}

ActionArm* ActionArm::GetInstance() {
	if (m_instance ==  0) {
		m_instance = new ActionArm();
		std::cout << "info: Creating ActionArm Class" << std::endl;
	}
	return m_instance;
}

void ActionArm::PortcullisMode(bool portcullis) {
	m_portcullis = portcullis;
	arm_solenoid->Set(m_portcullis);
}

void ActionArm::ChevyMode(bool chevy) {
	m_chevy = chevy;
	stop_solenoid->Set(m_chevy);
}
