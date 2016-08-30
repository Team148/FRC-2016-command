#ifndef HANGERARM_H
#define HANGERARM_H

#include "WPILib.h"
#include "Subsystems/HangerWinch.h"
#include "Constants/Ports.h"

class HangerArm: public Subsystem
{

public:
	static HangerArm* GetInstance();
	void Deploy();
	void Reset();
	bool IsDeployed();

private:
	HangerArm();
	static HangerArm* m_instance;
	bool m_deployed = false;
	DoubleSolenoid* solenoid;

};

#endif
