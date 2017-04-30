#pragma once

#include "Header1.h"

float dist(SDL_Point p, SDL_Point q);

class Rectangle{
public:
	Rectangle(int x, int y, int h, int w, Uint8 red, Uint8 green, Uint8 blue);

	Rectangle(SDL_Point pos, SDL_Point size, Uint8 red, Uint8 green, Uint8 blue);

	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setRect(SDL_Point pos, SDL_Point size);

	void setRect(int x, int y, int h, int w);

	int draw(SDL_Renderer* passed_renderer);

private:
	SDL_Rect rect;
	Uint8 r, g, b;
};

class Circle{
public:
	Circle();

	Circle(SDL_Point mid_point, int radius);

	void setAnchors(SDL_Point mid_point, int radius);


	void setAnchors(int x, int y, int radius);

	int draw(SDL_Renderer *renderer);



private:
	void setPoints();
	SDL_Point centre;
	int r;
	SDL_Point points[51];


};


class Bezier{
public:
	Bezier(SDL_Point x[4]);

	void setAnchors(SDL_Point x[4]);

	void setAnchors(int x[4], int y[4]);
	
	void setAnchors(int x, int y, int n);

	void setConstructor(bool on);

	int draw(SDL_Renderer *renderer);



private:
	void setPoints();

	int drawExtra(SDL_Renderer *renderer);

	Circle circles[4];
	SDL_Point a[4];
	SDL_Point points[101];
	bool constructors;
};