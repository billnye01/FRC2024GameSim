#pragma once

#include"Brain.h"
#include"RobotContruller.h"

static class SimProgramProbertys
{

public:
	SimProgramProbertys(Brain& brain, RobotContruller* robot);

	void SimUpdate(Brain& brain, Robot* robot);

};

