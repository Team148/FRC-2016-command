#ifndef RunCompressor_H
#define RunCompressor_H

#include "WPILib.h"
#include "Subsystems/Pneumatic.h"

class RunCompressor: public Command
{
public:
	RunCompressor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
