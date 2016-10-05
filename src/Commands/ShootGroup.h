#ifndef ShootGroup_H
#define ShootGroup_H

#include "Commands/CommandGroup.h"
#include "Commands/CatapultSub/OpenClampSub.h"
#include "Commands/CatapultSub/FireCatapult.h"
#include "Commands/ResetCatapult.h"
#include "WPILib.h"

class ShootGroup: public CommandGroup
{
public:
	ShootGroup(bool IsLong);
};

#endif
