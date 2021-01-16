#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<cstdlib>
#include "Tak2.h"
#define PI 3.14159265
using namespace std;
void Circle::render(SDL_Renderer* renderer)// we can not draw a circle using a line, but we can draw many lines tangent to a circle
{
	cout << "Circle" << " position: " << get_apoint() << " Radius: " << radius << endl;
	float x_one = this->get_cordinate(0); //center of the circle
	float y_one = this->get_cordinate(1);
	for (int i = 0;i < 51;i++)
	{
		float x_two = x_one + (radius * cos(2* PI* i/ 50));//point on circle
		float y_two = y_one + (radius * sin(2* PI *i/50));
		float x_three = x_two+10; //initial point of a line
		float y_three = (-(x_two - x_one) / (y_two - y_one)) * (x_three - x_two) + y_two;
		SDL_SetRenderDrawColor(renderer, this->get_acolor(0), this->get_acolor(1), this->get_acolor(2), this->get_acolor(3));
		SDL_RenderDrawLine(renderer, x_three, y_three, x_two, y_two);
		SDL_RenderPresent(renderer);

	}
}

void Rectangle::render(SDL_Renderer* renderer)
{
	cout << "Rectangle" << " position: " << get_apoint() << " width: " << width << "  height: " << height << endl;
	SDL_SetRenderDrawColor(renderer, this->get_acolor(0),this->get_acolor(1), this->get_acolor(2) , this->get_acolor(3));
	SDL_RenderDrawLine(renderer, this->get_cordinate(0),this->get_cordinate(1), this->get_cordinate(0) + width, this->get_cordinate(1));
	SDL_RenderPresent(renderer);
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1), this->get_cordinate(0), this->get_cordinate(1) + height);
	SDL_RenderPresent(renderer);
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1) + height, this->get_cordinate(0) + width, this->get_cordinate(1) + height);
	SDL_RenderPresent(renderer);
	SDL_RenderDrawLine(renderer, this->get_cordinate(0) + width, this->get_cordinate(1) + height, this->get_cordinate(0) + width, this->get_cordinate(1) );
	SDL_RenderPresent(renderer);
}

void Triangle::render(SDL_Renderer* renderer)
{
	cout << "Triangle" << " position: " << get_apoint() << " base: " << base << "  height: " << height << endl;
	SDL_SetRenderDrawColor(renderer, this->get_acolor(0), this->get_acolor(1), this->get_acolor(2), this->get_acolor(3));
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1), this->get_cordinate(0) + base, this->get_cordinate(1));
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1), this->get_cordinate(0) , this->get_cordinate(1) + height);
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1) + height, this->get_cordinate(0) + base, this->get_cordinate(1));

}




/*int main(int argc, char* argv[])
{
	Point2D point;
	point.x = 10;
	point.y = 10;
	int color_arr[4] = { 143,188,143,255 };
	Rectangle first(point, 300, 250, color_arr);
	Triangle second(point, 350, 250, color_arr);
	Point2D pointtwo;
	pointtwo.x = 200;
	pointtwo.y = 110;
	Circle thred (pointtwo, 100, color_arr);
	vector <Shape*> vector_Shaped;
	vector_Shaped.push_back(&first);
	vector_Shaped.push_back(&second);
	vector_Shaped.push_back(&thred);
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Shape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	vector_Shaped[0]->render(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	//SDL_RenderClear(renderer);
	vector_Shaped[1]->render(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	//SDL_RenderClear(renderer);
	vector_Shaped[2]->render(renderer);
	SDL_Delay(20000);
	return 0;
}*/
int main(int argc, char* argv[])
{
	vector <Shape*> vector_Shaped ;
	Triangle* triangleSelected= NULL;
	Rectangle* rectangleSelected = NULL;
	Circle* circleSelected = NULL;
	int color_arr[4] = { 143,188,143,255 };
	char userchose;
	bool gameOver = false;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Shape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	while (gameOver == false)
	{
		cout << " Menu\n  press\n   c For circle\n   r for Rectangle\n   t for Triangle\n   q to Quit\n   x to remove all shape from the vector" << endl;
		cin >> userchose;
		if (userchose == 'c')
		{
			Point2D point((rand() % 100+100), (rand() % 100+100));
			circleSelected = new Circle (point, (rand() % 90+10), color_arr);
			vector_Shaped.push_back(circleSelected);
		}
		if (userchose == 't')
		{
			Point2D point ((rand() % 100),(rand() % 100));
			triangleSelected= new Triangle (point, (rand() % 250+10), (rand() % 250+10), color_arr);
			vector_Shaped.push_back(triangleSelected);
		}
		if (userchose == 'r')
		{
			Point2D point;
			point.x = (rand() % 100);
			point.y = (rand() % 100);
			 rectangleSelected= new Rectangle(point, (rand() % 300), (rand() % 300), color_arr);
			vector_Shaped.push_back(rectangleSelected);
		}
		if (userchose == 'q')
		{
			gameOver == true;
			break;
		}

		if (userchose == 'x')
			vector_Shaped.clear();
	}
	int numElement = vector_Shaped.size();
	for (int i = 0;i < numElement;i++)
		vector_Shaped[i]->render(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(20000);
	for (vector<Shape*>::iterator cleaner = vector_Shaped.begin();
		cleaner != vector_Shaped.end(); ++cleaner) {
		delete* cleaner;
	}
	return 0;
}
