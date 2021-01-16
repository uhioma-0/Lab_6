#include"Task 2_lab4.h"
#include<SDL2/SDL.h>
using namespace std;
class Shape
{
private:
	Point2D  postion;
	int colorRGB[4];
public:
	Shape(int colorArr[4]);
	Shape(Point2D position, int color_array[4]);
	string get_apoint();
	float get_cordinate(int intercept);
	int get_acolor(int index);
	void setPoint(Point2D point);
	virtual void render(SDL_Renderer* renderer);
};

class Animal :public Shape
{
	const char* Image = "mickymouse.bmp";
	SDL_Surface* windowCanvas = SDL_LoadBMP(Image);
public:
	Animal(int colorArr[4]) :Shape(colorArr) {}
	Animal(Point2D point, int colorArr[4]) :Shape(point, colorArr) {}
	void render(SDL_Window* GameWindow, SDL_Surface* ScreenSurface, SDL_Texture* texture, SDL_Renderer* renderer, Point2D* point);
	virtual const char* getImage() = 0;
};
class Mouse :public Animal {
	const char* Image = "mickymouse.bmp";
	int colorArr[4] = { 200,200,200,255 };
public:
	Mouse() :Animal(colorArr) {}
	Mouse(Point2D point, int colorArr[4]) :Animal(point, colorArr) {}
	const char* getImage();
	//void render(SDL_Window* GameWindow,SDL_Renderer* Renderer,Point2D* point);
};
class Baby :public Animal {
	const char* Image = "baby.bmp";
	int colorArr[4] = { 200,200,200,255 };
public:
	Baby() :Animal(colorArr) {}
	Baby(Point2D point, int colorArr[4]) :Animal(point, colorArr) {}
	const char* getImage();

};
