#ifndef Drivetrain_H
#define Drivetrain_H

#include "WPILib.h"
#include "Math.h"
#include "Constants/Ports.h"
#include "Commands/DriveWithJoystick.h"

#define PI 3.14159265

class Drivetrain: public Subsystem {
public:
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(float ystick, float xstick);
	//void Arcade(Joystick joy);

	void ResetEncoders(); 					//Reset Both Encoders
	int CountToDist(int tick);				//convert encoder ticks to distance traveled
	void SetGear(bool gear);				//shift to given low/high gear
	void SwitchGear();						//shift to the other gear
	bool GetGear();							// get current gear
	void SetBrakeMode(bool on);				//set the drivetrain in/out of brake mode
	void SetVelocityMode();
	void SetVBusMode();
	void SetLeftDrive(float power);
	void SetRightDrive(float power);
	void SetPositionX(double posX);
	void SetPositionY(double posY);
	void SetDeltaX(double deltaX);
	void SetDeltaY(double deltaY);

	void UpdatePosition();
	float GetGyroAngle();
	double GetLDistance();
	double GetRDistance();
	double GetAvgDistance();
	double GetPositionX();
	double GetPositionY();
	Encoder* GetLEncoder();
	Encoder* GetREncoder();
	Gyro* GetGyro();

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
	PowerDistributionPanel *pdp;

	//Encoders
	Encoder *m_lEncoder;
	Encoder *m_rEncoder;
	int m_lEncoderDistance;
	int m_rEncoderDistance;

	//Gyro
	Gyro *m_gyro;

	//Drivetrain Position
	double m_posX;
	double m_posY;
	double m_prevDistance;
	double m_deltaDistance;
};

#endif
