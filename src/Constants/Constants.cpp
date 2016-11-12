/*
 * Constants.cpp
 *
 *  Created on: Nov 12, 2016
 *      Author: james_tonthat
 */

#include <Constants/Constants.h>


Constants::Constants() {
	m_Prefs = Preferences::GetInstance();

	//Catapult
	m_Prefs->PutDouble("CATAPULT_CANDY_SHORT_DWELL",0.1);
	m_Prefs->PutDouble("CATAPULT_SHOT_LONG_DWELL",0.2);
	m_Prefs->PutDouble("CATAPULT_SHOT_SHORT_DWELL",0.4);
	m_Prefs->PutDouble("CATAPULT_CLAMP_LONG_DWELL",0.2);
	m_Prefs->PutDouble("CATAPULT_CLAMP_SHORT_DWELL",0.1);


}

