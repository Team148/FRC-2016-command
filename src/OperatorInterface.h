/*
 * OperatorInterface.h
 *
 *  Created on: Aug 4, 2016
 *      Author: griggsjr
 */

#ifndef SRC_OPERATORINTERFACE_H_
#define SRC_OPERATORINTERFACE_H_

#include "WPILib.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOut.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/FlashlightOn.h"
#include "Commands/ShiftHighGear.h"
#include "Commands/BeamBreakIntake.h"

class OperatorInterface {
public:

	Joystick* GetJoystick();
	static OperatorInterface* GetInstance();
	int GetSelectorA();
	int GetSelectorB();
	int GetDSSwitches();

private:
	OperatorInterface();
	static OperatorInterface* m_instance;
	Joystick* m_operatorJoystick;
	Joystick* m_drvJoystick;
	Joystick* m_dsiBrickA;
	Joystick* m_dsiBrickB;

	JoystickButton* m_drvButton1;
	JoystickButton* m_drvButton2;
	JoystickButton* m_drvButton3;
	JoystickButton* m_drvButton4;
	JoystickButton* m_drvButton5;
	JoystickButton* m_drvButton6;
	JoystickButton* m_drvButton7;

	JoystickButton* m_opButton1;
	JoystickButton* m_opButton2;
	JoystickButton* m_opButton3;
	JoystickButton* m_opButton4;
	JoystickButton* m_opButton5;
	JoystickButton* m_opButton6;
	JoystickButton* m_opButton7;


	JoystickButton* m_brickAselect1;
	JoystickButton* m_brickAselect2;
	JoystickButton* m_brickAselect3;
	JoystickButton* m_brickAselect4;
	JoystickButton* m_brickAselect5;
	JoystickButton* m_brickAselect6;
	JoystickButton* m_brickAselect7;
	JoystickButton* m_brickAselect8;

	JoystickButton* m_brickBselect1;
	JoystickButton* m_brickBselect2;
	JoystickButton* m_brickBselect3;
	JoystickButton* m_brickBselect4;
	JoystickButton* m_brickBselect5;
	JoystickButton* m_brickBselect6;
	JoystickButton* m_brickBselect7;
	JoystickButton* m_brickBselect8;

	JoystickButton* m_dsiSw1;
	JoystickButton* m_dsiSw2;
	JoystickButton* m_dsiSw3;
	JoystickButton* m_dsiSw4;
	JoystickButton* m_dsiSw5;

};

#endif /* SRC_OPERATORINTERFACE_H_ */
