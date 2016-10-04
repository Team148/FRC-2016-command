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
	m_drvButton5 = new JoystickButton(m_drvJoystick, 5);
	m_drvButton6 = new JoystickButton(m_drvJoystick, 6);
	m_drvButton7 = new JoystickButton(m_drvJoystick, 7);

	//Driver Controls
	m_drvButton1->WhileHeld(new IntakeIn());
	m_drvButton2->WhileHeld(new IntakeOut());
	m_drvButton3->WhileHeld(new FlashlightOn());
	m_drvButton5->WhenPressed(new ActionArmChevy(true));
	m_drvButton5->WhenReleased(new ActionArmChevy(false));
	m_drvButton6->WhileHeld(new ShiftHighGear());
	m_drvButton7->WhileHeld(new BeamBreakIntake());


	//m_operatorJoystick = new Joystick(1);
	//m_opButton1 = new JoystickButton(m_operatorJoystick, 1);
	//m_opButton2 = new JoystickButton(m_operatorJoystick, 2);
	//m_opButton3 = new JoystickButton(m_operatorJoystick, 3);
	//m_opButton4 = new JoystickButton(m_operatorJoystick, 4);
	//m_opButton5 = new JoystickButton(m_operatorJoystick, 5);
	//m_opButton6 = new JoystickButton(m_operatorJoystick, 6);

	//DSI Controls
	m_dsiBrickA = new Joystick(2);
	m_dsiBrickB = new Joystick(3);

	m_brickAselect1 = new JoystickButton(m_dsiBrickA, 1);
	m_brickAselect2 = new JoystickButton(m_dsiBrickA, 2);
	m_brickAselect3 = new JoystickButton(m_dsiBrickA, 3);
	m_brickAselect4 = new JoystickButton(m_dsiBrickA, 4);
	m_brickAselect5 = new JoystickButton(m_dsiBrickA, 5);
	m_brickAselect6 = new JoystickButton(m_dsiBrickA, 6);
	m_brickAselect7 = new JoystickButton(m_dsiBrickA, 7);
	m_brickAselect8 = new JoystickButton(m_dsiBrickA, 8);

	m_brickBselect1 = new JoystickButton(m_dsiBrickB, 1);
	m_brickBselect2 = new JoystickButton(m_dsiBrickB, 2);
	m_brickBselect3 = new JoystickButton(m_dsiBrickB, 3);
	m_brickBselect4 = new JoystickButton(m_dsiBrickB, 4);
	m_brickBselect5 = new JoystickButton(m_dsiBrickB, 5);
	m_brickBselect6 = new JoystickButton(m_dsiBrickB, 6);
	m_brickBselect7 = new JoystickButton(m_dsiBrickB, 7);
	m_brickBselect8 = new JoystickButton(m_dsiBrickB, 8);

	m_dsiSw1 = new JoystickButton(m_dsiBrickA, 9);
	m_dsiSw2 = new JoystickButton(m_dsiBrickA, 10);
	m_dsiSw3 = new JoystickButton(m_dsiBrickA, 11);
	m_dsiSw4 = new JoystickButton(m_dsiBrickB, 9);
	m_dsiSw5 = new JoystickButton(m_dsiBrickB, 10);

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

int OperatorInterface::GetSelectorA() {
	if(m_brickAselect1->Get())
		return 1;
	if(m_brickAselect2->Get())
		return 2;
	if(m_brickAselect3->Get())
		return 3;
	if(m_brickAselect4->Get())
		return 4;
	if(m_brickAselect5->Get())
		return 5;
	if(m_brickAselect6->Get())
		return 6;
	if(m_brickAselect7->Get())
		return 7;
	if(m_brickAselect8->Get())
		return 8;

	return 0;
}

//TODO: Test GetSelectorA & B
int OperatorInterface::GetSelectorB() {
	if(m_brickBselect1->Get())
		return 1;
	if(m_brickBselect2->Get())
		return 2;
	if(m_brickBselect3->Get())
		return 3;
	if(m_brickBselect4->Get())
		return 4;
	if(m_brickBselect5->Get())
		return 5;
	if(m_brickBselect6->Get())
		return 6;
	if(m_brickBselect7->Get())
		return 7;
	if(m_brickBselect8->Get())
		return 8;

	return 0;
}

//TODO: Test GetDSSwitches
int OperatorInterface::GetDSSwitches() {
	int switches = 0;
	int sw1 = m_dsiSw1->Get();
	switches = sw1;
	int sw2 = m_dsiSw2->Get();
	switches = switches + (sw2 << 1);
	int sw3 = m_dsiSw3->Get();
	switches = switches + (sw3 << 2);
	int sw4 = m_dsiSw4->Get();
	switches = switches + (sw4 << 3);
	int sw5 = m_dsiSw5->Get();
	switches = switches + (sw5 << 4);

	return switches;
}
