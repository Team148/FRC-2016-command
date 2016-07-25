/*
 * Ports.h
 *
 *  Created on: Jul 24, 2016
 *      Author: justingriggs
 */

#ifndef SRC_CONSTANTS_PORTS_H_
#define SRC_CONSTANTS_PORTS_H_


class Ports {

	//Drivetrain CAN IDs
	public const int DRIVE_LEFT_1 = 2;
	public const int DRIVE_LEFT_2 = 3;
	public const int DRIVE_RIGHT_1 = 5;
	public const int DRIVE_RIGHT_2 = 4;
	public const int DRIVE_SHIFTER = 0;

	//Hanger Winch CAN ID
	public const int HANGER_WINCH = 6;

	//Hanger deploy (PCM 0)
	public const int HANGER_DEPLOY_1 = 1;
	public const int HANGER_DEPLOY_2 = 5;

	//Intake CAN IDs
	public const int INTAKE_ARM = 0;
	public const int INTAKE_ROLLER = 7;

	//Catapult solenoids (PCM 1)
	public const int CAT_SHOOTER_1 = 0;
	public const int CAT_SHOOTER_2 = 1;
	public const int CAT_SHOOTER_3 = 2;
	public const int CAT_SHOOTER_4 = 3;

	//Catapult solenoids (PCM 0)
	public const int CAT_SHORT_SHOT = 2;
	public const int CAT_CLAMP = 3;

	//Action Arm (PCM 0)
	public const int ACTION_ARM = 4;
	public const int ACTION_ARM_STOP = 6;

	//Flashlight Relay
	public const int FLASHLIGHT = 1;

	//Camera Rightlight
	public const int CAMERA_RING_LIGHT = 2;

	//Compressor Relay
	public const int COMPRESSOR_RELAY = 0;

};


#endif /* SRC_CONSTANTS_PORTS_H_ */
