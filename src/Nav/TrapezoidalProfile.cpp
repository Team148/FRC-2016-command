/*
 * TrapezoidalProfile.cpp
 *
 *  Created on: Oct 20, 2016
 *      Author: james_tonthat
 */

#include <Nav/TrapezoidalProfile.h>
#include <iostream>

TrapezoidalProfile::TrapezoidalProfile(double MaxVel, double MaxAccel) {
	m_MaxAccel = MaxAccel;
	m_MaxVel = MaxVel;
	profile = new AccelerationProfile();
}
double TrapezoidalProfile::GetVelocity(){
	return m_CurrentVel;
}

double TrapezoidalProfile::GetAcceleration(){
	return m_CurrentAccel;
}

double TrapezoidalProfile::GetPosition(){
	return m_CurrentPos;
}

void TrapezoidalProfile::Reset(){
	m_CurrentPos = 0;
	m_CurrentVel = 0;
	m_CurrentAccel = 0;
}

void TrapezoidalProfile::UpdateKinematics(double Accel, double dt){
	m_CurrentAccel = Accel;
	m_CurrentPos += m_CurrentVel*dt + 0.5*m_CurrentAccel*dt*dt;
	m_CurrentVel += m_CurrentAccel * dt;
}

void TrapezoidalProfile::GenerateAccelProfile(double ActualDistance, double ActualVel, double GoalVel){
	profile = new AccelerationProfile();
	// Figure out the sign of the acceleration at the end of the trapezoid
	double StartAccel = 0.0;
	if (ActualDistance > 0.0) {
		StartAccel = m_MaxAccel;
	}
	else {
		if (ActualDistance == 0.0)
			return;
		else {
		GenerateAccelProfile(-ActualDistance, -ActualVel, -GoalVel);
		profile->m_StartAccel *= -1;
		profile->m_EndAccel *= -1;
		return;
		}
	}

	// If we floored it the entire way, how fast would we go?
	// vf^2 = v_0^2 + 2*a*d (timeless equation)
	// vf = sqrt(v_0^2 + 2*a*d)
	double MaxAchievableVelocity = sqrt(ActualVel*ActualVel + 2*StartAccel*ActualDistance);
//	std::cout <<"MaxAchievableVelocity: " << MaxAchievableVelocity<<std::endl;
	double FinalAccel;
	double MaxGoalVelocity; //Largest Velocity Outputted to Hit Goal
	if(MaxAchievableVelocity >= GoalVel){
		FinalAccel = -m_MaxAccel;

	// Find the top speed we can get to while then decelerating to our goal speed
	// Here are the equations:
	//   vmax^2 = ActualVel^2 + 2*StartAccel*accelDistance (acceleration)
	//   vgoal^2 = vmax^2 + 2*final_a*decelDistance (deceleration)
	//   actualDistance = accelDistance + decelDistance (total distance)
	// By combining and solving for vmax, we obtain:
	//   accelDistance = (vmax^2 - actualSpeed^2)/(2*start_a)
	//   decelDistance = (vgoal^2 - vmax^2)/(2*final_a)
	//   actualDistance = (vmax^2 - actualSpeed^2)/(2*start_a) + (vgoal^2 - vmax^2)/(2*final_a)
	//   actualDistance = vmax^2/(2*start_a) - actualSpeed^2/(2*start_a) + vgoal^2/(2*final_a) - vmax^2/(2*final_a)
	//   vmax^2/(2*final_a) - vmax^2/(2*start_a) = -actualDistance - actualSpeed^2/(2*start_a) + vgoal^2/(2*final_a)
	//   vmax^2*(1/(2*final_a)-1/(2*start_a)) = -actualDistance - actualSpeed^2/(2*start_a) + vgoal^2/(2*final_a)
	//   vmax = sqrt( (-actualDistance - actualSpeed^2/(2*start_a) + vgoal^2/(2*final_a)) / (1/(2*final_a)-1/(2*start_a)) )
	MaxGoalVelocity = sqrt((-ActualDistance
						- (ActualVel*ActualVel) / (2.0*StartAccel)
						+ (GoalVel*GoalVel) / (2.0*FinalAccel))
						/ (1.0 / (2.0*FinalAccel) - 1.0 / (2.0 * StartAccel)));
//	std::cout <<"MaxGoalVelocity: " << MaxGoalVelocity<<std::endl;
	}
	else{
		FinalAccel = m_MaxAccel;
		MaxGoalVelocity = MaxAchievableVelocity;
	}

	double AccelTime = 0; //Time spent Acceleration
	double ConstTime = 0; //Time spent at constant velocity
	//If the profile exceeds max velocity capable, then limit the velocity
	if(MaxGoalVelocity > m_MaxVel){
		//Accel time is first part of the profile, calcs time to get to desired speed
		AccelTime = (m_MaxVel-ActualVel) / m_MaxAccel;
		//Time at Constant Velocity is found by
		//ConstantTime = ConstantDistance/ MaxVel
		//ConstantTime = (ActualDistance - AccelDistance - DecelDistance) / MaxVel
		ConstTime = (ActualDistance
				- ((m_MaxVel*m_MaxVel - ActualVel*ActualVel) / (2.0 * StartAccel))		//Accel Distance
				- ((GoalVel*GoalVel - m_MaxVel*m_MaxVel) / (2.0 * FinalAccel))	)		//Decel Distance
				/ m_MaxVel;
		MaxGoalVelocity = m_MaxVel;
	}
	else {	//Time it Takes to Reach Top Speed, if it's in the statement means that it is a pyramid profile
		AccelTime = (MaxGoalVelocity - ActualVel) / StartAccel;
	}
	profile->m_StartTime = fmax(AccelTime, 0.0);
	profile->m_StartAccel = StartAccel;
	profile->m_ConstTime = fmax(ConstTime, 0.0);
	profile->m_EndTime = fmax((GoalVel - MaxGoalVelocity) / FinalAccel, 0.0);
	profile->m_EndAccel = FinalAccel;
}

void TrapezoidalProfile::Update(double ActualDistance, double ActualVel, double GoalVel, double dt) {
	double m_dt = dt;

	this->GenerateAccelProfile(ActualDistance,ActualVel,GoalVel);
	if (profile->m_StartTime > m_dt) {
		this->UpdateKinematics(profile->m_StartAccel, m_dt);
	}
	else {
		this->UpdateKinematics(profile->m_StartAccel, profile->m_StartTime);
		dt -= profile->m_StartTime;

		if (profile->m_ConstTime > m_dt) {
			this->UpdateKinematics(0.0, m_dt);
		} else {
			this->UpdateKinematics(0.0, profile->m_ConstTime);
			dt -= profile->m_ConstTime;

			if (profile->m_EndTime > m_dt) {
				this->UpdateKinematics(profile->m_EndAccel, m_dt);
			} else {
				this->UpdateKinematics(profile->m_EndAccel, profile->m_EndTime);
				m_dt -= profile->m_EndTime;
				this->UpdateKinematics(0, dt);
			}
		}
	}
}

void TrapezoidalProfile::PrintAccelProfile()
{
   std::cout<<"m_StartAccel:"<<profile->m_StartAccel<<std::endl;
   std::cout<<"m_StartTime: "<<profile->m_StartTime<<std::endl;
   std::cout<<"m_ConstTime: "<<profile->m_ConstTime<<std::endl;
   std::cout<<"m_EndAccel:  "<<profile->m_EndAccel<<std::endl;
   std::cout<<"m_EndTime:   "<<profile->m_EndTime<<std::endl;
}

TrapezoidalProfile::AccelerationProfile::AccelerationProfile() {
	m_StartAccel = 0.0;
	m_StartTime = 0.0;
	m_ConstTime = 0.0;
	m_EndAccel = 0.0;
	m_EndTime = 0.0;
}

