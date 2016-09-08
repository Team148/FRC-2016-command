#include "Drivetrain.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	m_LeftMotor1 = new CANTalon(DRIVE_LEFT_1);
	m_LeftMotor2 = new CANTalon(DRIVE_LEFT_2);
	m_RightMotor1 = new CANTalon(DRIVE_RIGHT_1);
	m_RightMotor2 = new CANTalon(DRIVE_RIGHT_2);


	m_drive = new RobotDrive(m_LeftMotor1, m_RightMotor1, m_LeftMotor2, m_RightMotor2);
}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::Arcade(float ystick, float xstick) {


}
