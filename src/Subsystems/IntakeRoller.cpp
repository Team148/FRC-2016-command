#include "IntakeRoller.h"

IntakeRoller* IntakeRoller::m_instance = 0;  						//Global static pointer

IntakeRoller::IntakeRoller() : Subsystem("IntakeRoller") {
	std::cout << "RollerMotor constructor " << RollerMotor << std::endl;
	//RollerMotor = new CanTalonSRX(INTAKE_ROLLER);
	std::cout << "RollerMotor constructor " << RollerMotor << std::endl;
	//RollerMotor->SetModeSelect(CanTalonSRX::kMode_DutyCycle);
	//RollerMotor->Set(0); 											//recommended to call immediately after SetControlMode
	std::cout << "info: IntakeRoller class created" << std::endl;
}

IntakeRoller* IntakeRoller::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating IntakeRoller Class" << std::endl;
		std::cout << "m_instance " << m_instance << std::endl;
		m_instance = new IntakeRoller();
		std::cout << "m_instance " << m_instance << std::endl;
	}
	return m_instance;
}

void IntakeRoller::SetSpeed(double speed) {
	std::cout << "info: IntakeRoller SetSpeed before" << std::endl;
	std::cout << "RollerMotor " << RollerMotor << std::endl;
	CanTalonSRX* fakeRollerMotor = new CanTalonSRX(INTAKE_ROLLER);
	//m_speed = speed;
	fakeRollerMotor->Set(speed);
	std::cout << "info: IntakeRoller SetSpeed after" << std::endl;
}
