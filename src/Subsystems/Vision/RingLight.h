/*
 * RingLight.h
 *
 *  Created on: Jun 28, 2016
 *      Author: justin
 */

#ifndef SRC_SUBSYSTEMS_VISION_RINGLIGHT_H_
#define SRC_SUBSYSTEMS_VISION_RINGLIGHT_H_

class RingLight {
public:
	RingLight();
	virtual ~RingLight();

	//
	void SetRingLight(int on);

	bool IsRightLightOn();

private:
	bool _ison = 0;

};

#endif /* SRC_SUBSYSTEMS_VISION_RINGLIGHT_H_ */
