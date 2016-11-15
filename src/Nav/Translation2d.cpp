/*
 * Translation2d.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#include <Nav/Translation2d.h>
#include <Nav/Rotation2d.h>

Translation2d::Translation2d() {
	m_x = 0;
	m_y = 0;
}
Translation2d::Translation2d(double x , double y){
	m_x = x;
	m_y = y;
}
Translation2d::Translation2d(Translation2d other){
	m_x = other.m_x;
	m_y = other.m_y;
}
double Translation2d::norm(){
	return hypot(m_x, m_y);
}
double Translation2d::getX(){
	return m_x;
}
double Translation2d::getY(){
	return m_y;
}
void Translation2d::setX(double x){
	m_x = x;
}
void Translation2d::setY(double y){
	m_y = y;
}
/**
  * We can compose Translation2d's by adding together the x and y shifts.
  *
  * @param other
  *            The other translation to add.
  * @return The combined effect of translating by this object and the other.
  */
Translation2d Translation2d::translateBy(Translation2d other){
	return new Translation2d(m_x + other.m_x, m_y + other.m_y);
}

/**
 * We can also rotate Translation2d's. See:
 * https://en.wikipedia.org/wiki/Rotation_matrix
 *
 * @param rotation
 *            The rotation to apply.
 * @return This translation rotated by rotation.
 */
Translation2d Translation2d::rotateBy(Rotation2d rotation){
	return new Translation2d(m_x*rotation.getCos() - m_y*rotation.getSin(), m_x*rotation.sin()+m_y*rotation.cos());
}
