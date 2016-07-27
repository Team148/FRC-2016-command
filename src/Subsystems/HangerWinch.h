#ifndef HangerWinch_H
#define HangerWinch_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class HangerWinch: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	HangerWinch();
	void InitDefaultCommand();
};

#endif
