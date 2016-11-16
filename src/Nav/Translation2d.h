/*
 * Translation2d.h
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#ifndef SRC_NAV_TRANSLATION2D_H_
#define SRC_NAV_TRANSLATION2D_H_

#include "Math.h"
#include "Rotation2d.h"

class Translation2d {
public:
	Translation2d();
	Translation2d(double x, double y);
	Translation2d(const Translation2d& other);
	double norm();
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	Translation2d translateBy(const Translation2d& other);
	Translation2d rotateBy(Rotation2d rotation);
	Translation2d inverse();
	Translation2d interpolate(Translation2d other, double x);
	Translation2d extrapolate(Translation2d other, double x);
protected:
	double m_x;
	double m_y;
};

#endif /* SRC_NAV_TRANSLATION2D_H_ */
