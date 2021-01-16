#include"Task 2_lab4.h"
#include"GameWIndow.h"
#include<thread>
#include "ScoreRefere.h"

int main(int argc, char* argv[])
{
	int const screenPosition[6][2] = { {0,200},{0,400},{267,200},{267,400},{534,200},{534,400} };
	vector <Animal*> vector_Animal;
	window WickAMouse;
	WickAMouse.initWindow();
	WickAMouse.CreateWackAmole();
	thread ScoreGraphic(&window::GameGraphisLoader, &WickAMouse);
	Mouse* MickyMouse = new Mouse;
	Baby* babyCry = new Baby;
	vector_Animal.push_back(MickyMouse);
	vector_Animal.push_back(babyCry);
	//GameGraphics* GameGraphic = new GameGraphics;
	//GameGraphic->renderGraphic(WickAMouse.getRenderer());
	//auto renderer = WickAMouse.getRenderer();
	//thread GraphicDrawer(&GameGraphics::renderGraphic, &GameGraphic, renderer);

	bool EndWhestle = false;
	thread TimeController(&window::TimeControl, &WickAMouse, &EndWhestle);
	thread TimeDisplayer(&window::TimeDisplayer, &WickAMouse);
	while (EndWhestle==false)
	{
		SDL_Event event;
		SDL_Event event2;
		if (SDL_PollEvent(&event))
		{
			if(event.type== SDL_QUIT)
			{
				EndWhestle = false;
				break;
			}
			int randomCoadrant = rand() % 6;
			Point2D point((screenPosition[randomCoadrant][0]), (screenPosition[randomCoadrant][1]));
			int shapeToRender = (rand() % 2);
			vector_Animal[shapeToRender]->render(WickAMouse.getwindow(),WickAMouse.getSurface(),WickAMouse.getTexture(), WickAMouse.getRenderer(), &point);
			bool timePassed = false;
			thread drawtoscreen(&window::DisplayGame, &WickAMouse,&timePassed);
			
			while (!timePassed)
			{
				SDL_PollEvent(&event2);
				if (event2.type == SDL_MOUSEBUTTONDOWN)
				{
					WickAMouse.ScoreUpdate(&point, 267, 200, &event2, shapeToRender);
					break;
				}

			}
			drawtoscreen.join();
			SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);

		}
	}
	TimeController.join();
	TimeDisplayer.join();
	ScoreGraphic.join();
	return 0;
}