#include "SimProgramProbertys.h"

SimProgramProbertys::SimProgramProbertys(Brain& brain, RobotContruller* robotCon)
{

	SimProbertys simProbertys;

	//code goes here

	for (int i = 0; i <
		robotCon->getAllRobotValues().size() / robotCon->getRobotValues(1).size();
		i++) {
		simProbertys.setInput(
			simProbertys.genFloat(&robotCon->getRobot(0).getValues()[0], 
				std::string("Robot ") + std::to_string(i) + " X"));

		simProbertys.setInput(
			simProbertys.genFloat(&robotCon->getRobot(0).getValues()[1],
				std::string("Robot ") + std::to_string(i) + " Y"));

		simProbertys.setInput(
			simProbertys.genFloat(&robotCon->getRobot(0).getValues()[2], 
				std::string("Robot ") + std::to_string(i) + " Heading"));



		simProbertys.setInput(
			simProbertys.genFloat(&robotCon->getRobot(0).getValues()[3], 
				std::string("Robot ") + std::to_string(i) + " X Velocity"));

		simProbertys.setInput(
			simProbertys.genFloat(&robotCon->getRobot(0).getValues()[4], 
				std::string("Robot ") + std::to_string(i) + " Y Velocity"));

		simProbertys.genFloat(&robotCon->getRobot(0).getValues()[5], 
			std::string("Robot ") + std::to_string(i) + " Omega");
	}


	simProbertys.setOutput(
		simProbertys.genFloat(
			-1,
			1,
			"X change OUT"
		)
	);

	simProbertys.setOutput(
		simProbertys.genFloat(
			-1,
			1,
			"Y change OUT"
		)
	);

	simProbertys.setOutput(
		simProbertys.genFloat(
			-1,
			1,
			"Omga OUT"
		)
	);


	simProbertys.GenSetUp(
		{10, 10}
	);

	brain = Brain(simProbertys);

}

void SimProgramProbertys::SimUpdate(Brain& brain, Robot* robot)
{
	float xChange, yChange, Omega;

	brain.getValue("X change OUT", xChange);
	brain.getValue("Y change OUT", yChange);
	brain.getValue("Omga OUT", Omega);

	robot->change(
		{
			xChange,
			yChange,
			Omega

		}
	);

}
