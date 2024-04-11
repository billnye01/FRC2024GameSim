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
#include <algorithm>
#include "Saving.h"
#include "Brain.h"
#include "Sim.h"

bool sortF(int i, int j) { return (i < j); }

int main(int argc, char* argv[]){
	
	Saving save(std::string("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt"));

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
	//RobotContruller robotContuller;

	SimTemp simTemp;
	RobotContruller robotContuller;

	//blue
	Robot RobotBlue1(window.CreateEntdy(RobotPosY[1], RobotPosX[0], 0.1, window.LoadTexture("BlueAllanceRobot.png")), true);
	Robot RobotBlue2(window.CreateEntdy(RobotPosY[1], RobotPosX[1], 0.1, window.LoadTexture("BlueAllanceRobot.png")), true);
	Robot RobotBlue3(window.CreateEntdy(RobotPosY[1], RobotPosX[2], 0.1, window.LoadTexture("BlueAllanceRobot.png")), true);

	//red
	Robot RobotRed1(window.CreateEntdy(RobotPosY[0], RobotPosX[0], 0.1, window.LoadTexture("RedAllanceRobot.png")), false);
	Robot RobotRed2(window.CreateEntdy(RobotPosY[0], RobotPosX[1], 0.1, window.LoadTexture("RedAllanceRobot.png")), false);
	Robot RobotRed3(window.CreateEntdy(RobotPosY[0], RobotPosX[2], 0.1, window.LoadTexture("RedAllanceRobot.png")), false);

	robotContuller.setRobot(RobotBlue1, 0);
	robotContuller.setRobot(RobotBlue2, 1);
	robotContuller.setRobot(RobotBlue3, 2);
	robotContuller.setRobot(RobotRed1, 3);
	robotContuller.setRobot(RobotRed2, 4);
	robotContuller.setRobot(RobotRed3, 5);

	simTemp.robotCon = &robotContuller;

	Sim sim(simTemp);
	sim.Start(true, {10, 10});


	bool GameRuning = true;

	while (GameRuning) {
		GameRuning = checkSDL.CheckIfGameRunning();

		for (int i = 0; i < 3; i++) {

			if (i != 0) {
				sim.StartLoad("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt");
			}

			int cycalls = 600;
			bool runing = true;
			while (cycalls > 0)
			{
				cout << cycalls << "\n\n\n";

				sim.Update();

				window.Clear();
				window.renderAll();
				window.Display();

				cycalls--;
			}
			
			sim.End("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt");
			sim.Reset();
		}

	}

	window.CleanUp();
	SDL_Quit();

	//vector<int> bestRobots = robotContuller.getScores();

	//sort(bestRobots.begin(), bestRobots.end(), sortF);

	/*
	for (int i = 0; i < bestRobots.size(); i++) {
		cout << i << " : " << bestRobots[i] << endl;
	}*/

	sim.End("C:/Users/clywh/OneDrive/Desktop/Code/C/FRC2024GameSim/BaordGame/SaveFiles/SaveTest.txt");
	
	return 0;
}