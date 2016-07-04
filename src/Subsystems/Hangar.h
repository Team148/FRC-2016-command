/*
 * Hangar.h
 *
 *  Created on: Jul 1, 2016
 *      Author: justin
 */

#ifndef HANGAR_H_
#define HANGAR_H_

class Hangar {
public:
	Hangar();
	virtual ~Hangar();

	//setters
	void DeployArm();
	void WinchUp();
	void ResetArm();


	//getters
	bool ArmIsDeployed();
	bool ArmIsReset();

};

#endif /* HANGAR_H_ */
