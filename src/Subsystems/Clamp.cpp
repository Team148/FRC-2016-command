/*
 * Clamp.cpp
 *
 *  Created on: July 5, 2016
 *      Author: James Tonthat
 */

#include "Clamp.h"

Clamp *Clamp::m_instance = 0;

using namespace std;

Clamp::Clamp() : Subsystem("Clamp") {
	Clamp1 = new Solenoid(0,CAT_CLAMP);
}

Clamp* Clamp::GetInstance(){
	if(m_instance==0){
		m_instance = new Clamp();
		cout << "info: Creating Clamp Class" << endl;
	}
	return m_instance;
}

void Clamp::SetState(bool on){
	m_on = on;

	Clamp1->Set(m_on);
}

bool Clamp::GetState(){
	return m_on;
}
