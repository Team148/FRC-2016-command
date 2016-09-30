/*
 * CandyCane.h
 *
 *  Created on: July 5, 2016
 *      Author: James Tonthat
 */

#ifndef CandyCane_H
#define CandyCane_H

#include "WPILib.h"
#include "Constants/Ports.h"

class CandyCane : public Subsystem
{
public:
	static CandyCane* GetInstance();
	void SetState(bool on);
	bool GetState();

private:
	CandyCane();
	static CandyCane *m_instance;
	Solenoid *CandyCane1;

	bool m_on = 0;
};

#endif
