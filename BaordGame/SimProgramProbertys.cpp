#include "SimProgramProbertys.h"

SimProgramProbertys::SimProgramProbertys(Brain& brain, RobotContruller* robotCon)
{

	SimProbertys simProbertys;

	//code goes here

	for (int i = 0; i <
		robotCon->getAllRobotValues().size() / robotCon->getRobotValues(1).size();
		i++) {

	}


	simProbertys.setInput(
		simProbertys.genFloat(&robotCon->getRobot(0).getValues()[0],
			std::string("Robot ") + " X IN"));

	simProbertys.setInput(
		simProbertys.genFloat(&robotCon->getRobot(0).getValues()[1],
			std::string("Robot ") + " Y IN"));

	simProbertys.setInput(
		simProbertys.genFloat(&robotCon->getRobot(0).getValues()[2],
			std::string("Robot ") + " Heading IN"));



	simProbertys.setInput(
		simProbertys.genFloat(&robotCon->getRobot(0).getValues()[3],
			std::string("Robot ") + " X Velocity IN"));

	simProbertys.setInput(
		simProbertys.genFloat(&robotCon->getRobot(0).getValues()[4],
			std::string("Robot ") + " Y Velocity IN"));

	simProbertys.setInput(
		simProbertys.genFloat(&robotCon->getRobot(0).getValues()[5],
			std::string("Robot ") + " Omega IN"));



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
