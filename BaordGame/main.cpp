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
#include "Row.h"

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

	Row rowBlue1(6, 3);
	rowBlue1.RandomizeCells(0, 1, 0, 1);


	bool GameRuning = true;

	while (GameRuning) {
		GameRuning = checkSDL.CheckIfGameRunning();
		
		robotContuller.ModifiRobot(rowBlue1.out(robotContuller.getRobotValues(0)), 0);

		// do stuff
		robotContuller.UpdateAll();

		for (int i = 0; i < 6; i++)
		{
			if (i > 2) {
				BlueScore += robotContuller.getRobotValues(i)[1];
			}
			else
			{
				RedScore += robotContuller.getRobotValues(i)[1];
			}
			
		}

		window.Clear();
		window.renderAll();
		window.Display();
	}

	window.CleanUp();
	SDL_Quit();
	
	return 0;
}