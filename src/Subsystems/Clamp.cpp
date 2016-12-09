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

void Clamp::SetOpen(bool open){
	m_open = open;

	Clamp1->Set(m_open);
}

bool Clamp::GetState(){
	return m_open;
}

//everything to send to the Logger
void Clamp::Log() {
	//logger->AddtoBuffer("clamp position",std::to_string(m_open));
}
