/*
 * OperatorInterface.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: griggsjr
 */

#include <OperatorInterface.h>

OperatorInterface* OperatorInterface::m_instance = 0;

OperatorInterface::OperatorInterface() {

	std::cout << "info: creating operator interface." << std::endl;



}

Joystick* OperatorInterface::GetJoystick() {
	return m_drvJoystick;
}

OperatorInterface* OperatorInterface::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating OperatorInterface Class" << std::endl;
		m_instance = new OperatorInterface();
	}
	return m_instance;
}
