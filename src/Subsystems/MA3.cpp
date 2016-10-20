/*
 * MA3.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: justingriggs
 */

#include <Subsystems/MA3.h>


MA3::MA3(int port) {
	m_analogInput = new AnalogInput(port);
	m_analogInput->SetAverageBits(6);
}


void MA3::SetContinuousMode() {

}


void MA3::Reset() {
	m_num_rotations = 0;
	int calangle = m_analogInput->GetAverageVoltage();
	m_calibratedangle = calangle;
}


int MA3::GetRawAngle() {
	return m_analogInput->GetVoltage();
}
