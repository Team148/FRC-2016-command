#ifndef HangerArm_H
#define HangerArm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class HangerArm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	HangerArm();
	void InitDefaultCommand();
};

#endif
