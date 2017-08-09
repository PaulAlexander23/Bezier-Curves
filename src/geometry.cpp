#include"geometry.h"

float dist(SDL_Point p, SDL_Point q){
	return(sqrtf(pow(p.x - q.x, 2) + pow(p.y - q.y, 2)));
}


Rectangle::Rectangle(int x, int y, int h, int w, Uint8 red, Uint8 green, Uint8 blue)
	{
		rect.x = x;
		rect.y = y;
		rect.h = h;
		rect.w = w;
		r = red;
		g = green;
		b = blue;
	}

Rectangle::Rectangle(SDL_Point pos, SDL_Point size, Uint8 red, Uint8 green, Uint8 blue)
	{
		rect.x = pos.x;
		rect.y = pos.y;
		rect.h = size.y;
		rect.w = size.x;
		r = red;
		g = green;
		b = blue;
	}

void Rectangle::setColor(Uint8 red, Uint8 green, Uint8 blue){
		r = red;
		g = green;
		b = blue;
	}

void Rectangle::setRect(SDL_Point pos, SDL_Point size){
		rect.x = pos.x;
		rect.y = pos.y;
		rect.h = size.y;
		rect.w = size.x;
	}

void Rectangle::setRect(int x, int y, int h, int w){
		rect.x = x;
		rect.y = y;
		rect.h = h;
		rect.w = w;
	}

int Rectangle::draw(SDL_Renderer* passed_renderer)
	{
		SDL_SetRenderDrawColor(passed_renderer, r, g, b, 255);
		return SDL_RenderFillRect(passed_renderer, &rect);
	}



Circle::Circle()
	{
		centre.x = -1;
		centre.y = -1;
		r = 0;
		setPoints();
	}

Circle::Circle(SDL_Point mid_point, int radius)
	{
		centre = mid_point;
		r = radius;
		setPoints();
	}

void Circle::setAnchors(SDL_Point mid_point, int radius){
		centre = mid_point;
		r = radius;
		setPoints();
	}

void Circle::setAnchors(int x, int y, int radius){
		centre.x = x;
		centre.y = y;
		r = radius;
	}

int Circle::draw(SDL_Renderer *renderer){

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		return(SDL_RenderDrawLines(renderer, points, 51));
	}

void Circle::setPoints(){
		for (int i = 0; i < 51; i++){
			points[i].x = centre.x + int(r*cos(2 * M_PI*i*0.02));
			points[i].y = centre.y + int(r*sin(2 * M_PI*i*0.02));
		}
	}



Bezier::Bezier(SDL_Point x[4])
	{
		for (int i = 0; i < 4; i++){
			a[i] = x[i];
		}
		setPoints();

		constructors = false;
	}

void Bezier::setAnchors(SDL_Point x[4]){
		for (int i = 0; i < 4; i++){
			a[i] = x[i];
		}
		setPoints();
	}

void Bezier::setAnchors(int x[4], int y[4]){
		for (int i = 0; i < 4; i++){
			a[i].x = x[i];
			a[i].y = y[i];
		}
		setPoints();
	}

void Bezier::setAnchors(int x, int y, int n){
		a[n].x = x;
		a[n].y = y;

		setPoints();
	}

void Bezier::setConstructor(bool on){
		constructors = on;
	}

int Bezier::draw(SDL_Renderer *renderer){

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		if (constructors == true){
			drawExtra(renderer);
		}

		return(SDL_RenderDrawLines(renderer, points, 101));
	}

void Bezier::setPoints(){
		for (int i = 0; i < 101; i++){
			points[i].x = int(a[0].x * pow(1 - i*0.01, 3) + 3 * a[1].x * pow(1 - i*0.01, 2) * i*0.01 + 3 * a[2].x * (1 - i*0.01) * pow(i, 2) * 0.0001 + a[3].x * pow(i, 3) * 0.000001);
			points[i].y = int(a[0].y * pow(1 - i*0.01, 3) + 3 * a[1].y * pow(1 - i*0.01, 2) * i*0.01 + 3 * a[2].y * (1 - i*0.01) * pow(i, 2) * 0.0001 + a[3].y * pow(i, 3) * 0.000001);
		}
		for (int i = 0; i < 4; i++)
			circles[i].setAnchors(a[i], 10);

	}

int Bezier::drawExtra(SDL_Renderer *renderer){
		int fail = 0;
		fail = SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		fail += SDL_RenderDrawLine(renderer, a[0].x, a[0].y, a[1].x, a[1].y);
		fail += SDL_RenderDrawLine(renderer, a[2].x, a[2].y, a[3].x, a[3].y);
		for (int i = 0; i < 4; i++){
			fail += circles[i].draw(renderer);
		}
		if (fail < 0)
			fail = -1;
		return(fail);
	}
