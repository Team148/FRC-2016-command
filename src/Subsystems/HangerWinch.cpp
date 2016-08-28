#include "HangerWinch.h"

HangerWinch* HangerWinch::m_instance = 0;  						//Global static pointer

HangerWinch::HangerWinch() : Subsystem("HangerWinch") {
	WinchMotor = new CANTalon(HANGER_WINCH);
	WinchMotor->Set(0);

}


HangerWinch* HangerWinch::GetInstance() {
	if (m_instance ==  0) {
		m_instance = new HangerWinch();
		std::cout << "info: Creating HangerWinch Class" << std::endl;
	}
	return m_instance;
}


void HangerWinch::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void HangerWinch::SetSpeed(double speed) {
	if(speed <= 0.0)  //check that the motor only runs one way
		return;
	m_speed = speed;
	WinchMotor->Set(m_speed);

}


bool HangerWinch::IsExtended() {
	//if HangerArm has been deployed
	//then m_isExtended = 1;
	//else
	return m_isExtended;
}

void HangerWinch::Reset() {
	//if HangerArm is Reset,
	//then m_isExtended = 0;

}
