/*
 * TrapezoidalProfile.h
 *
 *  Created on: Oct 20, 2016
 *      Author: james_tonthat
 */

#ifndef SRC_NAV_TRAPEZOIDALPROFILE_H_
#define SRC_NAV_TRAPEZOIDALPROFILE_H_

#include <Math.h>



class TrapezoidalProfile {
public:
	TrapezoidalProfile(double MaxVel, double MaxAccel);
	double GetVelocity();
	double GetAcceleration();
	double GetPosition();
	void Reset();
	void UpdateKinematics(double Accel, double dt);
	void Update(double ActualDistance, double ActualVel, double GoalVel, double dt);
	void PrintAccelProfile();

private:
	class AccelerationProfile {
	public:
		AccelerationProfile();
		double m_StartAccel;
		double m_StartTime;
		double m_ConstTime;
		double m_EndAccel;
		double m_EndTime;
	};
	void GenerateAccelProfile(double ActualDistance, double ActualVel, double GoalVel);
	double m_CurrentAccel;
	double m_CurrentVel;
	double m_CurrentPos;
	double m_MaxVel;
	double m_MaxAccel;

	AccelerationProfile *profile;
};

#endif /* SRC_NAV_TRAPEZOIDALPROFILE_H_ */
