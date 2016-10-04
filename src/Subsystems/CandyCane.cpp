/*
 * CandyCane.cpp
 *
 *  Created on: July 5, 2016
 *      Author: James Tonthat
 */

#include "CandyCane.h"

CandyCane *CandyCane::m_instance = 0;

using namespace std;

CandyCane::CandyCane() : Subsystem("CandyCane") {
	CandyCane1 = new Solenoid(0,CAT_SHORT_SHOT);
}

CandyCane* CandyCane::GetInstance(){
	if(m_instance==0){
			m_instance = new CandyCane();
			cout << "info: Creating CandyCane Class" << endl;
		}
		return m_instance;
}

void CandyCane::SetState(bool on){
	m_on = on;

	CandyCane1->Set(m_on);
}

bool CandyCane::GetState(){
	return m_on;
}
