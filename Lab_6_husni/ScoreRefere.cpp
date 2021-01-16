#include "ScoreRefere.h"

void Score::scoreRefere(Point2D* point,int width,int hight, SDL_Event* event, int animalIdentifier, SDL_Window* currentWindow, SDL_Surface* ScreenSurface)//0 for mole 1 for baby
{
	if (animalIdentifier == 0)
	{
		if (point->x< event->button.x < point->x + width&& point->y < event->button.y < point->y + hight)
		{
			score = score + 1;
			SDL_FillRect(ScreenSurface, &ScoreText, SDL_MapRGB(ScreenSurface->format, 255, 255, 255));
			SDL_Surface* tempScoreDisplay = TTF_RenderText_Solid(font, to_string(score).c_str(), color);
			SDL_BlitSurface(tempScoreDisplay, NULL, ScreenSurface, &ScoreText);
			if(SDL_BlitSurface(tempScoreDisplay, NULL, ScreenSurface, &ScoreText) ==-1)
				cout << "not created" << endl;
			SDL_FreeSurface(tempScoreDisplay);
		}
	}
	else
	{
		if (point->x < event->button.x < point->x + width && point->y < event->button.y < point->y + hight)
		{
			score = score - 1;
			SDL_FillRect(ScreenSurface, &ScoreText, SDL_MapRGB(ScreenSurface->format, 255, 255, 255));
			SDL_Surface* tempScoreDisplay = TTF_RenderText_Solid(font, to_string(score).c_str(), color);
			SDL_BlitSurface(tempScoreDisplay, NULL, ScreenSurface, &ScoreText);
			if (SDL_BlitSurface(tempScoreDisplay, NULL, ScreenSurface, &ScoreText) == -1)
				cout << "not created" << endl;
			SDL_FreeSurface(tempScoreDisplay);
		}
	}
}


Score::Score()
{
	score = 0;
	ScoreText.w = 27;
	ScoreText.h = 27;
	ScoreText.x = 126;
	ScoreText.y = 120;

	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	font = TTF_OpenFont("ariblk.ttf", 20);
	if (font == NULL)
		cout << "font not loaded " <<SDL_GetError()<< endl;


}

void Score::displayScore(const char* FileLocation, SDL_Surface* ScreenSurface,SDL_Rect* rect)
{

	SDL_Surface* tempSurface = SDL_LoadBMP(FileLocation);
	//SDL_FillRect(ScreenSurface, &gamingArea, SDL_MapRGB(ScreenSurface->format, 255, 255, 255));
	SDL_BlitSurface(tempSurface, NULL, ScreenSurface, rect);
	SDL_FreeSurface(tempSurface);
}
