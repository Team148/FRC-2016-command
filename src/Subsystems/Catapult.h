/*
 * Catapult.h
 *
 *  Created on: July 5, 2016
 *      Author: Zach Cody
 */
#ifndef SRC_SUBSYSTEMS_CATAPULT_H_
#define SRC_SUBSYSTEMS_CATAPULT_H_


#include "WPILib.h"
#include "Constants/Ports.h"

class Catapult : public Subsystem
{
public:
	static Catapult* GetInstance();
	void SetState(bool on);

private:
	Catapult();
	static Catapult* m_instance;
	Solenoid* Catapult0;
	Solenoid* Catapult1;
	Solenoid* Catapult2;
	Solenoid* Catapult3;

	bool m_on = 0;


};

#endif // SRC_SUBSYSTEMS_CATAPULT_H_
