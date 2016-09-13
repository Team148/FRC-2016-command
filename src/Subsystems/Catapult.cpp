/*
 * Catapult.cpp
 *
 *  Created on: July 5, 2016
 *      Author: Zach Cody
 */

#include "Catapult.h"

Catapult *Catapult::m_instance = 0; // Global Static pointer

using namespace std;

Catapult::Catapult() : Subsystem("Catapult") {
	Catapult1 = new Solenoid(1,CAT_SHOOTER_1);
	Catapult2 = new Solenoid(1,CAT_SHOOTER_2);
	Catapult3 = new Solenoid(1,CAT_SHOOTER_3);
	Catapult4 = new Solenoid(1,CAT_SHOOTER_4);
	cout << "info: Catapult class created" << endl;
}

Catapult* Catapult::GetInstance() {
	if(m_instance==0){
		m_instance = new Catapult();
		std::count << "info: Creating Catapult Class" << std:endl;
	}
	return m_instance;
}

void Catapult::SetState(bool on){
	m_on = on;

	Catapult1->Set(m_on);
	Catapult2->Set(m_on);
	Catapult3->Set(m_on);
	Catapult4->Set(m_on);
}

bool Catapult::GetState(){
	return m_on;
}
