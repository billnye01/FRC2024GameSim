#pragma once

#include "Robot.h"

class RobotContruller
{

public:
	RobotContruller();

	void setRobot(Robot& robotIn, int i);
	void ModifiRobot(std::vector<int> in, int i);

	void UpdateAll();

	std::vector<int> getRobotValues(int i);
	std::vector<int> getAllRobotValues();

	Robot& getRobot(int i);

private:
	std::vector<Robot*> robots;

};

