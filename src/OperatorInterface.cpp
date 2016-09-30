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
	m_drvButton3 = new JoystickButton(m_drvJoystick, 3);
	m_drvButton4 = new JoystickButton(m_drvJoystick, 4);
	//m_drvButton5 = new JoystickButton(m_driverJoystick, 5);
	//m_drvButton6 = new JoystickButton(m_driverJoystick, 6);
	m_drvButton7 = new JoystickButton(m_drvJoystick, 7);

	//Driver Controls
	m_drvButton1->WhenPressed(new ToggleClamp());
	m_drvButton3->WhileHeld(new FlashlightOn());
	m_drvButton5->WhenPressed(new ActionArmChevy(true));
	m_drvButton5->WhenReleased(new ActionArmChevy(false));
	m_drvButton7->WhileHeld(new ActionArmDown());



	m_opJoystick = new Joystick(1);
	m_opButton1 = new JoystickButton(m_opJoystick, 1);
	m_opButton2 = new JoystickButton(m_opJoystick, 2);
	//m_opButton3 = new JoystickButton(m_opJoystick, 3);
	//m_opButton4 = new JoystickButton(m_opJoystick, 4);
	//m_opButton5 = new JoystickButton(m_opJoystick, 5);
	//m_opButton6 = new JoystickButton(m_opJoystick, 6);

	//Operator Controls
	m_opButton1->WhileHeld(new IntakeIn());
	m_opButton2->WhileHeld(new IntakeOut());


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
