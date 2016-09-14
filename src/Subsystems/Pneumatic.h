#ifndef Pneumatic_H
#define Pneumatic_H

#include "WPILib.h"
#include "Constants/Ports.h"


class Pneumatic: public Subsystem
{
public:
	static Pneumatic* GetInstance();
	void InitDefaultCommand();

private:
	Pneumatic();
	static Pneumatic *m_instance;
	Relay *m_relay;
	Compressor *m_comp;

};

#endif
