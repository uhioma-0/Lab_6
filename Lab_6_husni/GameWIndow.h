#include<SDL2/SDL.h>
#include<iostream>
#include"Task 2_lab4.h"
#include<vector>;
#include "GameTimmer.h"
using namespace std;

class window
{
	int width=0;
	int height=0;
	SDL_Color color;
	const char* windowName= "default";
	SDL_Window* currentWindow = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* Texture = nullptr;
	SDL_Surface* ScreenSurface = nullptr;

public:
	window();
	window(const char* windowName, SDL_Renderer* renderer, SDL_Surface* windowCanvas, int width, int height,SDL_Color color);
	~window();
	void initWindow();
	SDL_Window* getwindow();
	SDL_Renderer* getRenderer();
	SDL_Texture* getTexture();
	SDL_Surface* getSurface();
	void DisplayGame(bool* timePassed);
	void CreateWackAmole();
	void ScoreUpdate(Point2D* point, int width, int hight, SDL_Event* event, int animalIdentifier);
	SDL_Renderer* DrawAnobject();
	void GameGraphisLoader();
	void TimeControl(bool* EndWhestle);
	void TimeDisplayer();

};