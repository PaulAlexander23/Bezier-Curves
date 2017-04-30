#pragma once

#include "Header1.h"

class cSDL
{
public:
	cSDL(bool* quit, int ScreenWidth, int ScreenHeight);
	~cSDL();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

};

