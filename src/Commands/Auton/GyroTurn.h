#ifndef GyroTurn_H
#define GyroTurn_H


#include "WPILib.h"
#include "Subsystems/Drivetrain.h"

class GyroTurn: public Command
{
public:
	GyroTurn(float degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float m_setpoint;
	float m_preverror;
	float m_error;
	float m_kp;
	float m_kd;
	float m_errortolerance;
};

#endif
