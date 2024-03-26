#pragma once

#include "Entdy.h"

#include "vector"
#include <iostream>

using namespace std;

class Robot
{

public:
	Robot(Entdy* entdy);

	void update();

	void change(std::vector<float> inputs);
	std::vector<float> getValues();

private:
	Entdy* robot;

	double XChange = 0;
	double YChange = 0;
	double Omega = 0;
};

