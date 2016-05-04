#include "SDL_Setup.h"

CSDL_Setup::CSDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = NULL;
	window = SDL_CreateWindow("Scrabble", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout<<"window couldn't be created"<<std::endl;
		*quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	firstEvent = new SDL_Event();
}


CSDL_Setup::~CSDL_Setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete firstEvent;
}

SDL_Renderer* CSDL_Setup::GetRenderer()
{
	return renderer;
}

SDL_Event* CSDL_Setup::GetMainEvent()
{
	return firstEvent;
}

void CSDL_Setup::Begin()
{
		SDL_PollEvent(firstEvent);
		SDL_RenderClear(renderer);
}

void CSDL_Setup::Update()
{
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

}


void CSDL_Setup::End()
{
	SDL_RenderPresent(renderer);
}
