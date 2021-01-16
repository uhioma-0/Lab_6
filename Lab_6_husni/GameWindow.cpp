#include"GameWIndow.h"
#include"ScoreRefere.h"
using namespace std;
Score* ScoreGraphic= new Score();
GameTimmer* Watch = new GameTimmer(100);
window::window()
{
	width = 0;
	height = 0;
	color = { 0,0,0 };
	windowName = "default";
	currentWindow = nullptr;
	renderer = nullptr;
	ScreenSurface = nullptr;
}

window::window(const char* windowName, SDL_Renderer* renderer, SDL_Surface* ScreenSurface, int width, int height, SDL_Color color)
{
	this->windowName = windowName;
	this->renderer = renderer;
	this->width = width;
	this->height = height;
	this->color = color;
	this->ScreenSurface = ScreenSurface;

}

window::~window()
{
}

SDL_Renderer* window::getRenderer()//for getting the renderer
{
	return this->renderer;
}
SDL_Texture* window::getTexture()
{
	return Texture;
}
SDL_Surface* window::getSurface()
{
	return this->ScreenSurface;
}

SDL_Renderer* window::DrawAnobject()
{
	return this->renderer;
}

void window::GameGraphisLoader()//for loading game window graphics
{
	SDL_Rect rect;
	rect.w = 800;
	rect.h = 81;
	rect.x = 0;
	rect.y = 0;
	ScoreGraphic->displayScore("Gamename.bmp", ScreenSurface,&rect);
	rect.w = 800;
	rect.h = 119;
	rect.x = 0;
	rect.y = 81;
	ScoreGraphic->displayScore("ScoreBord.bmp", ScreenSurface,&rect);
}

void window::TimeControl(bool* EndWhestle)
{
	*EndWhestle = Watch->EndWhestle();//calling class for controlling the time of the game
}

void window::TimeDisplayer()
{
	Watch->TimeRenderer(currentWindow, ScreenSurface);
}

SDL_Window* window::getwindow()
{
	return this->currentWindow;
}

void window::initWindow()
{
	SDL_Init(SDL_INIT_VIDEO);
	currentWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(currentWindow, -1, SDL_RENDERER_ACCELERATED);
	ScreenSurface = SDL_GetWindowSurface(currentWindow);
}

void window::DisplayGame(bool* timePassed)
{
	SDL_UpdateWindowSurface(currentWindow);
	SDL_Delay(900);
	*timePassed = true;
}

void window::CreateWackAmole()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(currentWindow);
	SDL_Quit();

	width = 801;
	height = 600;
	color = { 255,255,255 };
	windowName = "WickAMole";
	currentWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(currentWindow, -1, SDL_RENDERER_ACCELERATED); 
	ScreenSurface= SDL_GetWindowSurface(currentWindow);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	
	/*SDL_Rect rect;
	rect.w = 267;
	rect.h = 200;
	rect.x = 0;
	rect.y = 200;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	rect.x = 0;
	rect.y = 400;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	rect.x = 267;
	rect.y = 200;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);;
	rect.x = 267;
	rect.y = 400;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	rect.x = 534;
	rect.y = 200;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	rect.x = 534;
	rect.y = 200;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	rect.x = 534;
	rect.y = 400;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	*/
}

void window::ScoreUpdate(Point2D* point, int width, int hight, SDL_Event* event, int animalIdentifier)
{
	ScoreGraphic->scoreRefere(point, width, hight, event, animalIdentifier,currentWindow, ScreenSurface);
}
