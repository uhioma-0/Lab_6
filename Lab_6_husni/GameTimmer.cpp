#include "GameTimmer.h"
#include<thread>
GameTimmer::GameTimmer(int Gametime)
{
	
	Rect.w = 27;
	Rect.h = 27;
	Rect.x = 126;
	Rect.y = 147;
	GameWatch = Gametime; 
	currentTime = 0;
	gameIsOff = false;
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	font = TTF_OpenFont("ariblk.ttf", 20);
	if (font == NULL)
		cout << "font not loaded " << SDL_GetError() << endl;
}
bool GameTimmer::EndWhestle()
{
		while ((GameWatch - currentTime) > 0)
		{
			this_thread::sleep_for(chrono::milliseconds(1000));
			currentTime = currentTime + 1;
		}
		gameIsOff = true;
		
		return gameIsOff;
	
}

int GameTimmer::getCurrentTime()
{
	while (gameIsOff == false)
	{
		return currentTime;
	}

}

void GameTimmer::TimeRenderer(SDL_Window* currentWindow,SDL_Surface* ScreenSurface)
{
	while (gameIsOff == false)
	{
		SDL_FillRect(ScreenSurface, &Rect, SDL_MapRGB(ScreenSurface->format, 255, 255, 255));
		SDL_Surface* tempScoreDisplay = TTF_RenderText_Solid(font, to_string(GameWatch-currentTime).c_str(), {255,0,0,255});
		SDL_BlitSurface(tempScoreDisplay, NULL, ScreenSurface, &Rect);
		if (SDL_BlitSurface(tempScoreDisplay, NULL, ScreenSurface, &Rect) == -1)
			cout << "Timmer not created" << endl;
		SDL_FreeSurface(tempScoreDisplay);
		SDL_UpdateWindowSurface(currentWindow);
}
}
