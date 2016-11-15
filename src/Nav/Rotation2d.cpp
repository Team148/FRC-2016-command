/*
 * Rotation2d.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#include <Nav/Rotation2d.h>

Rotation2d::Rotation2d() {
	this(1, 0, false);
}
Rotation2d::Rotation2d(double x, double y, bool normalize){
	m_cos_angle = x;
	m_sin_angle = y;
	if(normalize)
		this->normalize();
}

Rotation2d::Rotation2d(Rotation2d other){
	m_cos_angle = other.m_cos_angle;
	m_sin_angle = other.m_sin_angle;
}

static Rotation2d Rotation2d::fromRadians(double angle_radians){
	return new Rotation2d(cos(angle_radians), sin(angle_radians), false);
}

static Rotation2d Rotation2d::fromDegrees(double angle_degrees){
	return fromRadians(angle_degrees*3.14159265359*2.0);
}

void normalize(){

}
