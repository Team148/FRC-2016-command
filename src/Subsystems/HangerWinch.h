#ifndef HANGERWINCH_H
#define HANGERWINCH_H

#include "WPILib.h"
#include "Subsystems/HangerArm.h"
#include "Constants/Ports.h"
#include "CanTalon.h"

class HangerWinch: public Subsystem
{


public:
	static HangerWinch* GetInstance();
	//void InitDefaultCommand();  //not currently implemented
	void SetSpeed(double speed);
	bool IsExtended();
	void Reset();

private:
	HangerWinch();
	static HangerWinch* m_instance;
	CANTalon* WinchMotor;
	bool m_isExtended = 0;
	double m_speed = 0.0;
};

#endif
