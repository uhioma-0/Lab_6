#include <iostream>
#include <chrono>
#include <thread>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include <string>
using namespace std;

using namespace std;
class GameTimmer {
	int GameWatch;
	int currentTime;
	bool gameIsOff;
	TTF_Font* font = NULL;;
	SDL_Rect Rect;
public:
	GameTimmer(int Gametime);//:GameWatch(Gametime), currentTime(0), gameIsOff(false), font(){}
	bool EndWhestle();
	int getCurrentTime();
	void TimeRenderer(SDL_Window* currentWindow ,SDL_Surface* ScreenSurfac);
};
