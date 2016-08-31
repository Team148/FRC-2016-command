/*
 * Catapult.cpp
 *
 *  Created on: July 5, 2016
 *      Author: Zach Cody
 */

#include "Catapult.h"

Catapult* Catapult::m_instance = 0; // Global Static pointer

Catapult::Catapult() : Subsystem("Catapult") {
	Catapult0 = new Solenoid(1,CAT_SHOOTER_1);
	Catapult1 = new Solenoid(1,CAT_SHOOTER_2);
	Catapult2 = new Solenoid(1,CAT_SHOOTER_3);
	Catapult3 = new Solenoid(1,CAT_SHOOTER_4);
}

Catapult* Catapult::GetInstance() {
	if(m_instance==0){
		m_instance = new Catapult();
		std::count << "info: Creating Catapult Class" << std:endl;
	}
	return m_instance;
}

void Catapult::SetState(bool on)
{
	Catapult0->Set(on);
	Catapult1->Set(on);
	Catapult2->Set(on);
	Catapult3->Set(on);
}
