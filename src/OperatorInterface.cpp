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

	m_drvJoystick = new Joystick(0);
	m_drvButton1 = new JoystickButton(m_drvJoystick, 1);
	m_drvButton2 = new JoystickButton(m_drvJoystick, 2);


	//JoystickButton* m_drvButton3 = new JoystickButton(m_driverJoystick, 3);
	//JoystickButton* m_drvButton4 = new JoystickButton(m_driverJoystick, 4);
	//JoystickButton* m_drvButton5 = new JoystickButton(m_driverJoystick, 5);
	m_drvButton6 = new JoystickButton(m_drvJoystick, 6);

	//Driver Controls
	m_drvButton1->WhileHeld(new IntakeIn());
	m_drvButton2->WhileHeld(new IntakeOut());

	m_drvButton6->WhileHeld(new ShiftHighGear());


	//m_operatorJoystick = new Joystick(1);
	//JoystickButton* m_opButton1 = new JoystickButton(m_operatorJoystick, 1);
	//JoystickButton* m_opButton2 = new JoystickButton(m_operatorJoystick, 2);
	//JoystickButton* m_opButton3 = new JoystickButton(m_operatorJoystick, 3);
	//JoystickButton* m_opButton4 = new JoystickButton(m_operatorJoystick, 4);
	//JoystickButton* m_opButton5 = new JoystickButton(m_operatorJoystick, 5);
	//JoystickButton* m_opButton6 = new JoystickButton(m_operatorJoystick, 6);


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
