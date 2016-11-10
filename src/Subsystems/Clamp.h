/*
 * Clamp.h
 *
 *  Created on: July 5, 2016
 *      Author: James Tonthat
 */

#ifndef Clamp_H
#define Clamp_H

#include "Robot.h"


class Clamp : public Subsystem
{
public:
	static Clamp* GetInstance();
	void SetOpen(bool open);
	bool GetState();
	void Log();

private:
	Clamp();
	static Clamp *m_instance;
	Solenoid *Clamp1;
	bool m_open = 0;

};



#endif
