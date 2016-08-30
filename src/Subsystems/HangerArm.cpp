#include "HangerArm.h"

HangerArm* HangerArm::m_instance = 0;  						//Global static pointer

HangerArm::HangerArm() : Subsystem("HangerArm") {
	solenoid = new DoubleSolenoid(0, HANGER_DEPLOY_1, HANGER_DEPLOY_2);

}


HangerArm* HangerArm::GetInstance() {
	if (m_instance ==  0) {
		m_instance = new HangerArm();
		std::cout << "info: Creating HangerArm Class" << std::endl;
	}
	return m_instance;
}


void HangerArm::Deploy() {
	solenoid->Set(DoubleSolenoid::kForward);
	m_deployed = true;

}


void HangerArm::Reset() {
	solenoid->Set(DoubleSolenoid::kReverse);
	m_deployed = false;
}

bool HangerArm::IsDeployed() {
	return m_deployed;
}
