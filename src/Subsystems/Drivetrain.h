#ifndef Drivetrain_H
#define Drivetrain_H

#include "Robot.h"
#include "Commands/DriveWithJoystick.h"




class Drivetrain: public Subsystem {
public:
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(float ystick, float xstick);

	void ResetEncoders(); 							//Reset Both Encoders
	int CountToDist(int tick);						//convert encoder ticks to distance traveled
	void SetGear(bool gear);						//shift to given low/high gear
	void SwitchGear();								//shift to the other gear
	bool GetGear();						// get current gear
	void SetBrakeMode(bool on);						//set the drivetrain in/out of brake mode
	void SetLeftDrive(float power);
	void SetRightDrive(float power);
	float GetGyroAngle();
	Encoder* GetLEncoder();
	Encoder* GetREncoder();

	//Logger functions
	void Log();
	void LogPDP();

private:
	Drivetrain();
	static Drivetrain *m_instance;


	CANTalon *m_LeftMotor1;
	CANTalon *m_LeftMotor2;
	CANTalon *m_RightMotor1;
	CANTalon *m_RightMotor2;

	RobotDrive *m_drive;

	//Shifter Solenoid
	Solenoid *m_shifter;
	bool m_gear;


	//PDP
	PowerDistributionPanel *m_pdp;

	//Encoders
	Encoder *m_lEncoder;
	Encoder *m_rEncoder;
	int m_lEncoderDistance;
	int m_rEncoderDistance;

	//Gyro
	Gyro *m_gyro;
};

#endif
