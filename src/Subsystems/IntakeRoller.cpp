#include "IntakeRoller.h"


IntakeRoller::IntakeRoller() : Subsystem("IntakeRoller") {
	m_rollerMotor = new CanTalonSRX(Ports::INTAKE_ROLLER);

}

IntakeRoller* IntakeRoller::GetInstance() {
	if(m_instance == 0)
		m_instance = new IntakeRoller();

	return m_instance;
}

void IntakeRoller::SetRollerSpeed(double speed) {
	m_speed = speed;
	m_rollerMotor->Set(m_speed);
}
