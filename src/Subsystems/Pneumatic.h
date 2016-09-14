#ifndef Pneumatic_H
#define Pneumatic_H

#include "WPILib.h"
#include "Constants/Ports.h"
#include "Commands/RunCompressor.h"


class Pneumatic: public Subsystem
{
public:
	static Pneumatic* GetInstance();
	void InitDefaultCommand();
	void SetCompressor(bool on);		//turn the compressor on or off.

	Compressor *m_comp;
private:
	Pneumatic();
	static Pneumatic *m_instance;
	Relay *m_relay;


};

#endif
