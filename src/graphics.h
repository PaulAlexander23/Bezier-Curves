#pragma once

#include"main.h"

class cSDL
{
public:
	cSDL(bool* quit, int ScreenWidth, int ScreenHeight);
	~cSDL();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();
    int PollEvent();

	void Begin();
	void End();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

};

