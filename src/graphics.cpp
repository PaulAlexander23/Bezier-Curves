#include"graphics.h"

cSDL::cSDL(bool* quit, int ScreenWidth, int ScreenHeight)
{

	window = NULL;
	window = SDL_CreateWindow("TitleScreen", 40, 40, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Window counldn't be created" << std::endl;
		*quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	mainEvent = new SDL_Event();
}

cSDL::~cSDL()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* cSDL::GetRenderer()
{
	return renderer;
}

SDL_Event* cSDL::GetMainEvent()
{
	return mainEvent;
}

int cSDL::PollEvent()
{
	return SDL_PollEvent(mainEvent);
}

void cSDL::Begin()
{
	SDL_RenderClear(renderer);
}

void cSDL::End()
{
	SDL_RenderPresent(renderer);
}
