#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include"Shape.h"

class Score
{
	int score=0;
	SDL_Rect ScoreText;
	TTF_Font* font;
	SDL_Color color = { 0,0,0,0 };

public:
	void scoreRefere(Point2D* point, int width, int hight, SDL_Event* event, int animalIdentifier,SDL_Window* currentWindow, SDL_Surface* ScreenSurface);
	Score();
	void displayScore(const char* FileLocation, SDL_Surface* ScreenSurface,SDL_Rect* rect);
};
