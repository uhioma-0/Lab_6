/*#include"Task2_lab6_Game.h"
#include<vector>;
using namespace std;

window::window()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	currentWindow = SDL_CreateWindow("DefaultWinow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
}

window::window(const char* windowName, int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	currentWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
}

window::~window()
{
}

void window::clear()
{
	renderer = SDL_CreateRenderer(currentWindow, -1, SDL_RENDERER_ACCELERATED);

}

void window:: setRenderer(SDL_Renderer* renderer)
{
		this->renderer = renderer;
}
SDL_Renderer* window::getRenderer()
{
	return this->renderer;
}
void window::deleteRenderer()
{
	this->renderer = nullptr;
}
void window::pullEvent()
{
}
SDL_Window* window::getwindow()
{
	return this->currentWindow;
}
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
void Shape::render(SDL_Renderer* renderer)
{
}
void Shape::setPoint(Point2D point)
{
	this->postion = point;
}
Shape::Shape(Point2D position,int color_array[4])
{
	for (int i = 0; i < 4; i++)
	{
		if (color_array[i] >= 0 && color_array[i] <= 255)
			colorRGB[i] = color_array[i];
	}
}
string Shape::get_apoint() {
	return postion.toString();
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
void Rectangle::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, this->get_acolor(0), this->get_acolor(1), this->get_acolor(2), this->get_acolor(3));
	SDL_Rect rect;
	rect.w = this->width;
	rect.h = this->height;
	rect.x = this->get_cordinate(0);
	rect.y = this->get_cordinate(1);
	SDL_RenderFillRect(renderer,&rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderPresent(renderer);
	cout<<"rectangle" <<endl;
	SDL_Delay(500);

}


void Triangle::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, this->get_acolor(0), this->get_acolor(1), this->get_acolor(2), this->get_acolor(3));
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1), this->get_cordinate(0) + base, this->get_cordinate(1));
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1), this->get_cordinate(0), this->get_cordinate(1) + height);
	SDL_RenderDrawLine(renderer, this->get_cordinate(0), this->get_cordinate(1) + height, this->get_cordinate(0) + base, this->get_cordinate(1));
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderPresent(renderer);
	cout << "triangl" << endl;
	SDL_Delay(500);
}


void Animal::render(SDL_Window* GameWindow,SDL_Renderer* renderer,Point2D* point)
{

	SDL_Rect rect;
	rect.w = 45;
	rect.h = 50;
	rect.x = point->x;
	rect.y = point->y;
	windowCanvas = SDL_GetWindowSurface(GameWindow);
	SDL_FillRect(windowCanvas, NULL, SDL_MapRGB(windowCanvas->format, 255, 255, 255));
	SDL_BlitSurface(this->getImage(), NULL, windowCanvas, &rect);	
	SDL_UpdateWindowSurface(GameWindow);;
	SDL_Delay(500);
	//SDL_FreeSurface(this->getImage());
	//SDL_FreeSurface(windowCanvas);

}
SDL_Surface* Baby::getImage()
{
	return this->Image;
}

SDL_Surface* Mouse::getImage()
{
	return this->Image;
}

SDL_Texture* Score::LoadScore(const string &fontLocation, int Font_size, const string& ScoreText, const SDL_Color& TextColor)
{
	TTF_Font* ScoreFont=TTF_OpenFont(fontLocation.c_str(), Font_size);
	auto scoreSurface = TTF_RenderText_Solid(ScoreFont, ScoreText.c_str(), TextColor);
	SDL_Texture* ScoreTextureCreated = SDL_CreateTextureFromSurface(renderer, scoreSurface);
	return ScoreTextureCreated;
}

Score::Score(SDL_Renderer* renderer,const string &fontLocation, int Font_size, const string &ScoreText, const SDL_Color &TextColor)
{
	this->renderer = renderer;
	ScoreTexture = LoadScore(fontLocation, Font_size, ScoreText, TextColor);
	SDL_QueryTexture(ScoreTexture, nullptr, nullptr, &ScoreBox->w, &ScoreBox->h);

}

void Score::UpdateScore()
{
}

void Score::DisplayScore(int x, int y, SDL_Renderer* renderer)
{
	ScoreBox->x = x;
	ScoreBox->y = y;
	SDL_RenderCopy(renderer, ScoreTexture,nullptr, ScoreBox);
}

int main(int argc, char* argv[])
{
	int colorArr[4] = { 0, 0, 200, 255 };
	vector <Shape*> vector_Shape;
	vector <Animal*> vector_Animal;
	Triangle* triangleCharacter=new Triangle(colorArr);
	Rectangle* rectangleCharacter=new Rectangle(colorArr);
	Mouse* MickyMouse= new Mouse(colorArr);
	Baby* babyCry = new Baby(colorArr);
	vector_Shape.push_back(rectangleCharacter);
	vector_Shape.push_back(triangleCharacter);
	vector_Shape.push_back(rectangleCharacter);
	vector_Animal.push_back(MickyMouse);
	vector_Animal.push_back(babyCry);
	const int Font_size = 20;
	window GameWindow("wich-a-Rectangle", 800, 600);
	Score gameScore(GameWindow.renderer,"ariblk.ttf", 20, "SCORE 0", {255,0,0,255});
	GameWindow.clear();
	while (true)
	{
		gameScore.DisplayScore(20, 20, GameWindow.getRenderer());
		Point2D point((rand() % (800-45)), (rand() % (600-50)));
		int shapeToRender = (rand()%4);
		
		if (shapeToRender > 1)
			vector_Animal[shapeToRender - 2]->render(GameWindow.getwindow(), GameWindow.getRenderer(), &point);
		else
		{
			vector_Shape[shapeToRender]->setPoint(point);
			vector_Shape[shapeToRender]->render(GameWindow.getRenderer());
		}
	}
	return 0;
}
*/
