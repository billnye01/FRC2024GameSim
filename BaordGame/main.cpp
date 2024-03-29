#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "CheckSDL.h"
#include "Entdy.h"
#include "RobotContruller.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <chrono>
#include <ctime>
#include "Brain.h"

int main(int argc, char* argv[]){


						//blue 0  //blue 1  //blue 2
	int RobotPosX[3] = {170,		  275,		500};
					    // top  // bottom
	int RobotPosY[2] = { 1100,    100 };

	int BlueScore = 0;
	int RedScore = 0;

	double ThreashouldToHit = 10;
	int PenltyFromHitting = 100;

	// init video stuff
	CheckSDL checkSDL;
	
	RenderWindow window("Game", 1280, 720);
	
	window.SetImageOrgin("TextureFolders/Img/");

	window.SetSizeMod(1.0f);

	Entdy* backDrop = window.CreateEntdy(0, 0, 2.3, window.LoadTexture("FRC2024Fiald.png"));

	// makes the robots
	RobotContruller robotContuller;

	Robot blue1(window.CreateEntdy(RobotPosY[1], RobotPosX[0], 0.1, window.LoadTexture("BlueAllanceRobot.png")));
	Robot blue2(window.CreateEntdy(RobotPosY[1], RobotPosX[1], 0.1, window.LoadTexture("BlueAllanceRobot.png")));
	Robot blue3(window.CreateEntdy(RobotPosY[1], RobotPosX[2], 0.1, window.LoadTexture("BlueAllanceRobot.png")));

	Robot red1(window.CreateEntdy(RobotPosY[0], RobotPosX[0], 0.1, window.LoadTexture("RedAllanceRobot.png")));
	Robot red2(window.CreateEntdy(RobotPosY[0], RobotPosX[1], 0.1, window.LoadTexture("RedAllanceRobot.png")));
	Robot red3(window.CreateEntdy(RobotPosY[0], RobotPosX[2], 0.1, window.LoadTexture("RedAllanceRobot.png")));

	// sets the robots in robotContuller
	robotContuller.setRobot(blue1, 0);
	robotContuller.setRobot(blue2, 1);
	robotContuller.setRobot(blue3, 2);
	robotContuller.setRobot(red1, 3);
	robotContuller.setRobot(red2, 4);
	robotContuller.setRobot(red3, 5);

	Brain blue1_B( { 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	blue1_B.BrainRandomize(-1, 1, -1, 1);

	Brain blue2_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	blue2_B.BrainRandomize(-1, 1, -1, 1);

	Brain blue3_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	blue3_B.BrainRandomize(-1, 1, -1, 1);

	Brain red1_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	red1_B.BrainRandomize(-1, 1, -1, 1);

	Brain red2_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	red2_B.BrainRandomize(-1, 1, -1, 1);

	Brain red3_B({ 10, 10 }, 3, robotContuller.getAllRobotValues().size());
	red3_B.BrainRandomize(-1, 1, -1, 1);


	bool GameRuning = true;

	while (GameRuning) {
		GameRuning = checkSDL.CheckIfGameRunning();
		
		robotContuller.ModifiRobot(blue1_B.out(robotContuller.getAllRobotValues()), 0);
		robotContuller.ModifiRobot(blue2_B.out(robotContuller.getAllRobotValues()), 1);
		robotContuller.ModifiRobot(blue3_B.out(robotContuller.getAllRobotValues()), 2);

		robotContuller.ModifiRobot(red1_B.out(robotContuller.getAllRobotValues()), 3);
		robotContuller.ModifiRobot(red2_B.out(robotContuller.getAllRobotValues()), 4);
		robotContuller.ModifiRobot(red3_B.out(robotContuller.getAllRobotValues()), 5);


		// do stuff
		robotContuller.UpdateAll();

		window.Clear();
		window.renderAll();
		window.Display();
	}

	window.CleanUp();
	SDL_Quit();

	RedScore += robotContuller.getRobot(3).getScore();
	RedScore += robotContuller.getRobot(4).getScore();
	RedScore += robotContuller.getRobot(5).getScore();

	BlueScore += robotContuller.getRobot(0).getScore();
	BlueScore += robotContuller.getRobot(1).getScore();
	BlueScore += robotContuller.getRobot(2).getScore();


	if (RedScore > BlueScore) {
		cout << "RED WON!!";
	}
	else
	{
		cout << "BLUE WON!!!";
	}
	
	return 0;
}