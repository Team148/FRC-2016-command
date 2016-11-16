/*
 * RigidTransform2d.h
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#ifndef SRC_NAV_RIGIDTRANSFORM2D_H_
#define SRC_NAV_RIGIDTRANSFORM2D_H_

#include "Translation2d.h"
#include "Rotation2d.h"

class RigidTransform2d {
public:
	class Delta {
		public:
			Delta();
			Delta(double dx, double dy, double dtheta);
			double dx;
			double dy;
			double dthetha;
	};
	RigidTransform2d();
	RigidTransform2d(Translation2d translation, Rotation2d rotation);
	//RigidTransform2d(RigidTransform2d other);
	static RigidTransform2d fromTranslation(Translation2d translation);
	static RigidTransform2d fromRotation(Rotation2d rotation);
	static RigidTransform2d fromVelocity(Delta delta);
	Translation2d getTranslation();
	void setTranslation(Translation2d translation);
	Rotation2d getRotation();
	void setRotation(Rotation2d rotation);
	RigidTransform2d transformBy(RigidTransform2d other);
	RigidTransform2d inverse();
	RigidTransform2d interpolate(RigidTransform2d other, double x);

protected:
	Translation2d m_translation;
	Rotation2d m_rotation;

private:
	const double kEps = 1E-9;
};

#endif /* SRC_NAV_RIGIDTRANSFORM2D_H_ */
