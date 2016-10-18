#ifndef ShootGroup_H
#define ShootGroup_H

#include "Commands/CatapultSub/FireCatapult.h"
#include "Commands/CatapultSub/ResetCatapult.h"
#include "Commands/CatapultSub/ShotPrep.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class ShootCatapult: public CommandGroup
{
public:
	ShootCatapult(bool IsLong);
};

#endif
