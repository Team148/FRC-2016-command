#ifndef Flashlight_H
#define Flashlight_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Flashlight: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Flashlight();
	void InitDefaultCommand();
};

#endif
