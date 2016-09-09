#include "Drivetrain.h"


Drivetrain *Drivetrain::m_instance = 0;  						//Global static pointer

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	m_LeftMotor1 = new CANTalon(DRIVE_LEFT_1);
	m_LeftMotor2 = new CANTalon(DRIVE_LEFT_2);
	m_RightMotor1 = new CANTalon(DRIVE_RIGHT_1);
	m_RightMotor2 = new CANTalon(DRIVE_RIGHT_2);

	m_drive = new RobotDrive(m_LeftMotor1, m_RightMotor1, m_LeftMotor2, m_RightMotor2);

	//Pneumatics
	m_comp = new Compressor(0); //TODO: add Constant
	m_compSpike = new Relay(COMPRESSOR_RELAY);
}


Drivetrain* Drivetrain::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Drivetrain Class" << std::endl;
		m_instance = new Drivetrain();
	}
	return m_instance;
}


void Drivetrain::InitDefaultCommand()
{

	SetDefaultCommand(new DriveWithJoystick());
}


void Drivetrain::Arcade(float ystick, float xstick) {
	m_drive->ArcadeDrive(ystick,xstick);
}


//void Drivetrain::Arcade(Joystick joy) {
//	m_drive->ArcadeDrive(joy, false);
//}
