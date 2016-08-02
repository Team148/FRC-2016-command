/*
 * Ports.h
 *
 *  Created on: Jul 24, 2016
 *      Author: justingriggs
 */

#ifndef SRC_CONSTANTS_PORTS_H_
#define SRC_CONSTANTS_PORTS_H_


class Ports {

public:
	//Drivetrain CAN IDs
	const int DRIVE_LEFT_1 = 2;
	const int DRIVE_LEFT_2 = 3;
	const int DRIVE_RIGHT_1 = 5;
	const int DRIVE_RIGHT_2 = 4;
	const int DRIVE_SHIFTER = 0;

	//Hanger Winch CAN ID
	const int HANGER_WINCH = 6;

	//Hanger deploy (PCM 0)
	const int HANGER_DEPLOY_1 = 1;
	const int HANGER_DEPLOY_2 = 5;

	//Intake CAN IDs
	const int INTAKE_ARM = 0;
	const int INTAKE_ROLLER = 7;

	//Catapult solenoids (PCM 1)
	const int CAT_SHOOTER_1 = 0;
	const int CAT_SHOOTER_2 = 1;
	const int CAT_SHOOTER_3 = 2;
	const int CAT_SHOOTER_4 = 3;

	//Catapult solenoids (PCM 0)
	const int CAT_SHORT_SHOT = 2;
	const int CAT_CLAMP = 3;

	//Action Arm (PCM 0)
	const int ACTION_ARM = 4;
	const int ACTION_ARM_STOP = 6;

	//Flashlight Relay
	const int FLASHLIGHT = 1;

	//Camera Rightlight
	const int CAMERA_RING_LIGHT = 2;

	//Compressor Relay
	const int COMPRESSOR_RELAY = 0;


	//sensors
	const int INTAKE_BEAM_BREAK = 1;
	const int DRIVETRAIN_ENCODER_LEFT_A = 3;
	const int DRIVETRAIN_ENCODER_LEFT_B = 4;
	const int DRIVETRAIN_ENCODER_RIGHT_A = 1;
	const int DRIVETRAIN_ENCODER_RIGHT_B = 2;

	//SPARE_TALON = 1

};


#endif /* SRC_CONSTANTS_PORTS_H_ */
