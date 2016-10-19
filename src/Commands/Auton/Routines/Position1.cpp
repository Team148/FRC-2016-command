#include "Position1.h"

Position1::Position1(int defense, int actions)
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	//if actions contains SnatchNGrab
	//do snatchGrab
	//since defense is always lowbar, no decision is made for defense
	//Drive forward X distance
	//Drop ActionArms
	//Drop Intake
	//Do "drive over lowbar" routine
	//Drive X distance

	//if action contains "Shoot"
	//turn Right Y degrees
	//Drive X distance


}
