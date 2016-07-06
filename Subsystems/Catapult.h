/*
 * Catapult.h
 *
 *  Created on: July 5, 2016
 *      Author: Zach Cody
 */
#ifndef SRC_SUBSYSTEMS_CATAPULT_H_
#define SRC_SUBSYSTEMS_CATAPULT_H_


#include "Timer.h"
#include "WPILib.h"

class Catapult
{
public:
	Catapult();
	virtual~Catapult();


	//setters
	void SetClamp();
	void SetCandyCane();
	void SetCatapult();

	//getters
	bool InShortShot();
	bool InLongShot();
	bool IsClampOpen();
	bool IsCandyCane_Short();
};

#endif // SRC_SUBSYSTEMS_CATAPULT_H_
