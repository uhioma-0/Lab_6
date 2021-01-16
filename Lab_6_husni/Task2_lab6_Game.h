/*
#include "SDL_ttf.h"
#include"SDL.h"
#include"Task 2_lab4.h"
using namespace std;
class window
{
	string windowName;
	int width;
	int height;
	SDL_Window* currentWindow;
public:
		SDL_Renderer* renderer = nullptr;
		window();
		window(const char* windowName, int width, int height);
		~window();
		void clear();
		void pullEvent();
		SDL_Window* getwindow();
		void setRenderer(SDL_Renderer* renderer);
		SDL_Renderer* getRenderer();
		void deleteRenderer();
};
class Shape
{
private:
	Point2D  postion;
	int colorRGB[4];
public:
	Shape(int colorArr[4]);
	Shape(Point2D position,int color_array[4]);
	virtual void render(SDL_Renderer* renderer);
	string get_apoint();
	float get_cordinate(int intercept);
	int get_acolor(int index);
	void setPoint(Point2D point);
};

class Rectangle : public Shape {
public:
	float width;
	float height;
	Rectangle(int colorArr[4]) :width(45), height(50), Shape(colorArr) {}
	Rectangle(Point2D point, int colorArr[4]) :width(50), height(40), Shape(point, colorArr)
	{}
	void render(SDL_Renderer* renderer);
};

class Triangle : public Shape {
public:
	float base;
	float height;
	Triangle(int colorArr[4]):base(45),height(50),Shape(colorArr){}
	Triangle(Point2D point, int colorArr[4]) : base(45), height(50), Shape(point,colorArr)
	{}
	void render(SDL_Renderer* renderer);


};
class Animal:public Shape
{
	SDL_Surface* Image = nullptr;
	SDL_Surface* windowCanvas = nullptr;
public:
	Animal(int colorArr[4]) :Shape(colorArr) {}
	Animal(Point2D point, int colorArr[4]) :Shape(point, colorArr) {}
	void render(SDL_Window* GameWindow, SDL_Renderer* Renderer, Point2D* point);
	virtual SDL_Surface* getImage()=0;
};
class Mouse:public Animal {
	SDL_Surface* Image= SDL_LoadBMP("mickymouse.bmp");;
	SDL_Surface* windowCanvas=nullptr;
public:
	Mouse(int colorArr[4]):Animal(colorArr) {}
	Mouse(Point2D point, int colorArr[4]):Animal(point, colorArr) {}
	SDL_Surface* getImage();
	//void render(SDL_Window* GameWindow,SDL_Renderer* Renderer,Point2D* point);
};
class Baby :public Animal {
	SDL_Surface* Image = SDL_LoadBMP("baby.bmp");
	SDL_Surface* windowCanvas = nullptr;
public:
	Baby(int colorArr[4]) :Animal(colorArr) {}
	Baby(Point2D point, int colorArr[4]) :Animal(point, colorArr) {}
	SDL_Surface* getImage();
	
};
class Score
{
	string fileLocation;
	SDL_Texture* ScoreTexture;
	SDL_Rect* ScoreBox;
	SDL_Renderer* renderer;
	
public:
	SDL_Texture* LoadScore(const string &fontLocation, int Font_size, const string& ScoreText, const SDL_Color &TextColor);
	Score(SDL_Renderer* renderer, const string& fontLocation,int FOnt_size,const string &ScoreText,const SDL_Color& TextColor);
	void UpdateScore();
	void DisplayScore(int x, int y, SDL_Renderer* renderer);
		

};*/