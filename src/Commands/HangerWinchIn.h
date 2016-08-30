#ifndef HangerWinchIn_H
#define HangerWinchIn_H

#include "WPILib.h"
#include "Subsystems/HangerWinch.h"
#include "Subsystems/HangerArm.h"

class HangerWinchIn: public Command
{
public:
	HangerWinchIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	HangerWinch* m_hangerWinch;
	HangerArm* m_hangerArm;
};

#endif
