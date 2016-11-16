/*
 * RigidTransform2d.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#include <Nav/RigidTransform2d.h>

RigidTransform2d::RigidTransform2d() {
	m_translation = new Translation2d();
	m_rotation = new Rotation2d();
}

RigidTransform2d::RigidTransform2d(Translation2d translation, Rotation2d rotation){
	m_translation = translation;
	m_rotation = rotation;
}

//RigidTransform2d::RigidTransform2d(RigidTransform2d other){
//	m_translation = new Translation2d(other.m_translation);
//	m_rotation = new Rotation2d(other.m_rotation);
//}



