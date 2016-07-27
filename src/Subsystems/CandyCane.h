#ifndef CandyCane_H
#define CandyCane_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CandyCane: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	CandyCane();
	void InitDefaultCommand();
};

#endif
