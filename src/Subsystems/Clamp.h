#ifndef Clamp_H
#define Clamp_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Clamp: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Clamp();
	void InitDefaultCommand();
};

#endif
