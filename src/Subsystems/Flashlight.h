#ifndef Flashlight_H
#define Flashlight_H

#include "WPILib.h"
#include "Constants/Ports.h"

class Flashlight : public Subsystem
{
private:
	Flashlight();
	static Flashlight *m_instance;
	Relay *FlashlightRelay;


public:
	static Flashlight* GetInstance();
	void TurnOn();
	void TurnOff();
};

#endif
