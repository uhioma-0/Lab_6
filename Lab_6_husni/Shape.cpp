#include"Shape.h"
#include<vector>
Shape::Shape(int color_array[4])
{
	postion.x = 0;
	postion.y = 0;
	for (int i = 0; i < 4; i++)
	{
		if (color_array[i] >= 0 && color_array[i] <= 255)
			colorRGB[i] = color_array[i];
	}
}

void Shape::setPoint(Point2D point)
{
	this->postion = point;
}

void Shape::render(SDL_Renderer* renderer)
{
}

Shape::Shape(Point2D position, int color_array[4])
{
	for (int i = 0; i < 4; i++)
	{
		if (color_array[i] >= 0 && color_array[i] <= 255)
			colorRGB[i] = color_array[i];
	}
}
float Shape::get_cordinate(int intercept)
{
	if (intercept == 0)
		return postion.x;
	if (intercept == 1)
		return postion.y;
	else
		return 0;
}
int Shape::get_acolor(int index)
{
	if (index >= 0 and index <= 3)
		return colorRGB[index];
	else
		return 0;
}


const char* Baby::getImage()
{
	return this->Image;
}

const char* Mouse::getImage()
{
	return this->Image;
}

void Animal::render(SDL_Window* GameWindow,SDL_Surface* ScreenSurface, SDL_Texture* texture,SDL_Renderer* renderer, Point2D* point)
{
	SDL_Rect rect;
	rect.w = 267;
	rect.h = 200;
	rect.x = point->x;
	rect.y = point->y;
	SDL_Rect gamingArea;
	gamingArea.w = 801;
	gamingArea.h = 400;
	gamingArea.x = 0;
	gamingArea.y =200;
	SDL_Surface* windowCanvas = SDL_LoadBMP(this->getImage());
	SDL_FillRect(ScreenSurface, &gamingArea, SDL_MapRGB(ScreenSurface->format, 255, 255, 255));
	SDL_BlitSurface(windowCanvas, NULL, ScreenSurface, &rect);
	SDL_FreeSurface(windowCanvas);
	//*timePassed = true;*/
}


