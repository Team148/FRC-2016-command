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


int MA3::GetCalibratedAngle() {


	//check for rollover

	//return current angle relative to calibrated angle minus rotations
}


//Reset the Encoder to set the Zero point to the current angle.
void MA3::Reset() {
	m_num_rotations = 0;
	int calval = m_analogInput->GetAverageVoltage();
	m_zeropoint = calval;
}


int MA3::GetRawVoltage() {
	return m_analogInput->GetVoltage();
}


int MA3::GetRawAngle() {
	return 2 * M_PI * m_analogInput->GetVoltage() / 5.0;  //returns angle in radians
}
