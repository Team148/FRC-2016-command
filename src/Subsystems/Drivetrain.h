#ifndef Drivetrain_H
#define Drivetrain_H

#include "WPILib.h"
#include "Constants/Ports.h"
#include "Commands/DriveWithJoystick.h"

class Drivetrain: public Subsystem
{

public:
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(float ystick, float xstick);
	//void Arcade(Joystick joy);

private:
	Drivetrain();
	static Drivetrain *m_instance;

	CANTalon *m_LeftMotor1;
	CANTalon *m_LeftMotor2;
	CANTalon *m_RightMotor1;
	CANTalon *m_RightMotor2;

	RobotDrive *m_drive;

	//Compressor
	Compressor *m_comp;
	Relay *m_compSpike;

	//left encoder
	//Right encoder

};

#endif
