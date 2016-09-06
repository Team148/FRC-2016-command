#include "IntakeRoller.h"

IntakeRoller *IntakeRoller::m_instance = 0;  						//Global static pointer

using namespace std;

IntakeRoller::IntakeRoller() : Subsystem("IntakeRoller") {
	cout << "IntakeRoller constructor " << endl;
	RollerMotor = new CanTalonSRX(INTAKE_ROLLER);
	//RollerMotor->Set(0); 											//recommended to call immediately after SetControlMode
	cout << "info: IntakeRoller class created on port " << INTAKE_ROLLER << endl;
}

IntakeRoller* IntakeRoller::GetInstance() {
	if (m_instance ==  0) {
		cout << "info: GetInstance Creating IntakeRoller Class" << endl;
		m_instance = new IntakeRoller();
	}
	return m_instance;
}

void IntakeRoller::SetSpeed(double speed) {
	//cout << "info: IntakeRoller SetSpeed set to " << speed << endl;
	//cout << "RollerMotor " << RollerMotor << endl;
	m_speed = speed;
	RollerMotor->Set(speed);
	//cout << "info: IntakeRoller SetSpeed after" << endl;
}
