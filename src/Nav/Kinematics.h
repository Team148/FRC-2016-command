/*
 * Kinematics.h
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#ifndef SRC_NAV_KINEMATICS_H_
#define SRC_NAV_KINEMATICS_H_

#include "RigidTransform2d.h"

/**Inspired by 254 (https://github.com/Team254/FRC-2016-Public/blob/master/src/com/team254/frc2016/Kinematics.java)
 * Provides forward and inverse kinematics equations for the robot modeling the
 * wheelbase as a differential drive (with a corrective factor to account for
 * the inherent skidding of the center 4 wheels quasi-kinematically).
 */

class Kinematics {
public:
	Kinematics();
	RigidTransform2d.Delta forwardKinematics(double left_wheel_delta, double right_wheel_delta);
private:
	static const double kEpsilon = 1E-9;
};

#endif /* SRC_NAV_KINEMATICS_H_ */
