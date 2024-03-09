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

	void change(std::vector<int> inputs);
	std::vector<int> getValues();

private:
	Entdy* robot;

	int XChange = 0;
	int YChange = 0;
	int Omega = 0;
};

