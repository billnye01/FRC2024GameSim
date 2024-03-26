#pragma once

#include "Robot.h"

class RobotContruller
{

public:
	RobotContruller();

	void setRobot(Robot& robotIn, int i);
	void ModifiRobot(std::vector<float> in, int i);

	void UpdateAll();

	std::vector<float> getRobotValues(int i);
	std::vector<float> getAllRobotValues();

	Robot& getRobot(int i);

private:
	std::vector<Robot*> robots;

};

