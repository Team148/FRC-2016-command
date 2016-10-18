#ifndef ShotPrep_H
#define ShotPrep_H

#include "WPILib.h"
#include "Commands/CommandGroup.h"
#include <Commands/CatapultSub/CloseCandyCane.h>
#include <Commands/CatapultSub/OpenClamp.h>

class ShotPrep: public CommandGroup
{
public:
	ShotPrep(bool IsLong);
};

#endif
