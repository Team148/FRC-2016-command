/*
 * Clamp.h
 *
 *  Created on: July 5, 2016
 *      Author: James Tonthat
 */

#ifndef Clamp_H
#define Clamp_H

#include "WPILib.h"
#include "Constants/Ports.h"

class Clamp: public Subsystem
{
public:
	static Clamp* GetInstance();
	void SetState(bool on);
	bool GetState();

private:
	Clamp();
	static Clamp *m_instance;
	Solenoid *Clamp1;
	bool m_on = 0;

};



#endif
