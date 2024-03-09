#include "RobotContruller.h"

RobotContruller::RobotContruller()
{
    robots = std::vector<Robot*>(6);
}

void RobotContruller::setRobot(Robot& robotIn, int i)
{
    if (i >= 0 && i < robots.size()) {
        robots[i] = &robotIn;
    }
}

void RobotContruller::ModifiRobot(std::vector<int> in, int i)
{
    robots[i]->change(in);
}

void RobotContruller::UpdateAll()
{
    for (int i = 0; i < robots.size(); i++) {
        robots[i]->update();
    }
}

std::vector<int> RobotContruller::getRobotValues(int i)
{
    return robots[i]->getValues();
}

std::vector<int> RobotContruller::getAllRobotValues()
{
    std::vector<int> out;

    int indexOn = 0;
    for (int i = 0; i < robots.size(); i++) {
        for (int j = 0; j < robots[i]->getValues().size(); j++) {
            out[indexOn] = robots[i]->getValues()[j];
            indexOn++;
        }
    }

    return out;
}

Robot& RobotContruller::getRobot(int i)
{
    return *robots[i];
}
