/*
 * RigidTransform2d.h
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#ifndef SRC_NAV_RIGIDTRANSFORM2D_H_
#define SRC_NAV_RIGIDTRANSFORM2D_H_

class RigidTransform2d {
public:
	RigidTransform2d();
	static class Delta{
	public:
		Delta(double dx, double dy, double dtheta);
		double dx;
		double dy;
		double dthetha;
	};
};

#endif /* SRC_NAV_RIGIDTRANSFORM2D_H_ */
