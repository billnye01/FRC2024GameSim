#include "Robot.h"

Robot::Robot(Entdy* entdy) :robot(entdy)
{
}

void Robot::update()
{
	//cout << "Update, X change -" << XChange << endl;
	robot->x += XChange;
	robot->y += YChange;
}

void Robot::change(std::vector<float> inputs)
{
	XChange = inputs[0];
	YChange = inputs[1];
	Omega = inputs[2];
}

std::vector<float> Robot::getValues()
{
	std::vector<float> out(6);

	out[0] = robot->x;
	out[1] = robot->y;
	out[2] = robot->x;
	out[3] = XChange;
	out[4] = YChange;
	out[4] = Omega;

	return out;
}
