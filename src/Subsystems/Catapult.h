/*
 * Catapult.h
 *
 *  Created on: July 5, 2016
 *      Author: James Tonthat
 */

#ifndef SRC_SUBSYSTEMS_CATAPULT_H_
#define SRC_SUBSYSTEMS_CATAPULT_H_


#include "WPILib.h"
#include "Constants/Ports.h"

class Catapult : public Subsystem
{
public:
	static Catapult* GetInstance();
	void SetOpen(bool on);
	bool IsOpen();

private:
	Catapult();
	static Catapult *m_instance;
	Solenoid *Catapult1;
	Solenoid *Catapult2;
	Solenoid *Catapult3;
	Solenoid *Catapult4;

	bool m_on = 0;


};

#endif // SRC_SUBSYSTEMS_CATAPULT_H_
