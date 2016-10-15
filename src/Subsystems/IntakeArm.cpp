/*
 * IntakeArm.cpp
 *
 *  Created on: July 6, 2016
 *      Author: Zach Cody
 */
#include "IntakeArm.h"

IntakeArm* IntakeArm::m_instance = 0;  						//Global static pointer

IntakeArm::IntakeArm() : Subsystem("IntakeArm") {
	ArmMotor = new CanTalonSRX(INTAKE_ARM);
	ArmMotor->SetModeSelect(CanTalonSRX::kMode_DutyCycle);
	ArmMotor->Set(0);

}
IntakeArm* IntakeArm::GetInstance() {
	if (m_instance ==  0) {
		m_instance = new IntakeArm();
		std::cout << "info: Creating IntakeArm Class" << std::endl;
	}
	return m_instance;
}
void IntakeArm::SetSpeed(double speed) {
	m_speed = speed;
	ArmMotor->Set(m_speed);
}
