#include "IntakeRoller.h"

IntakeRoller* IntakeRoller::m_instance = 0;  						//Global static pointer

IntakeRoller::IntakeRoller() : Subsystem("IntakeRoller") {
	RollerMotor = new CanTalonSRX(INTAKE_ROLLER);
	RollerMotor->SetModeSelect(CanTalonSRX::kMode_DutyCycle);
	RollerMotor->Set(0); 											//recommended to call immediately after SetControlMode

}

IntakeRoller* IntakeRoller::GetInstance() {
	if (m_instance ==  0) {
		m_instance = new IntakeRoller();
		std::cout << "info: Creating IntakeRoller Class" << std::endl;
	}
	return m_instance;
}

void IntakeRoller::SetSpeed(double speed) {
	m_speed = speed;
	RollerMotor->Set(m_speed);
}
