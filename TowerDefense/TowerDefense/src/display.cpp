#include <iostream>

#include "display.h"

Display::Display()
{
	this->window = nullptr;
	this->renderer = nullptr;
	this->font = nullptr;
}

Display::~Display()
{
	TTF_CloseFont(this->font);
	TTF_Quit();
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();

	std::cout << "Display destroyed" << std::endl;
}

Display::Display(const Display &other)
{
	this->window = other.window;
	this->renderer = other.renderer;
	this->font = other.font;
}

Display &Display::operator=(const Display &other)
{
	this->window = other.window;
	this->renderer = other.renderer;
	this->font = other.font;

	return *this;
}

void Display::initAll()
{
	this->initSDL();
	this->initSDLImg();
	this->initSDLWindow();
	this->initSDLRenderer();
	this->initSDLFont();
}

void Display::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Unable to initialize SDL:" << 
			SDL_GetError() << std::endl;
	}
}

void Display::initSDLImg()
{
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;

	if ((flags & IMG_Init(flags)) != flags)
	{
		std::cout << "IMG_Init:" <<
			IMG_GetError() << std::endl;
	}
}

void Display::initSDLWindow()
{
	this->window = SDL_CreateWindow("Tower Defense",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_SIZE_X, WINDOW_SIZE_Y, 0);

	if (this->window == NULL)
	{
		std::cout << "Unable to initialize Window:" <<
			SDL_GetError() << std::endl;
	}
}

void Display::initSDLRenderer()
{
	this->renderer = SDL_CreateRenderer(this->window,
		-1, SDL_RENDERER_PRESENTVSYNC);

	if (this->renderer == NULL)
	{
		std::cout << "Unable to initialize Renderer:" <<
			SDL_GetError() << std::endl;
	}

	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
}

void Display::initSDLFont()
{
	if (TTF_Init() == -1)
	{
		std::cout << "Unable to initialize TTF_Init:" <<
			TTF_GetError() << std::endl;
	}

	this->font = TTF_OpenFont("assets/tower_defense.ttf", 65);

	if (this->font == NULL)
	{
		std::cout << "Unable to initialize Font:" <<
			TTF_GetError() << std::endl;
	}
}

void Display::clearRenderer()
{
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->renderer);
}

void Display::presentRenderer()
{
	SDL_RenderPresent(this->renderer);
}

SDL_Window &Display::getWindow()
{
	return *this->window;
}

SDL_Renderer &Display::getRenderer()
{
	return *this->renderer;
}

TTF_Font &Display::getFont()
{
	return *this->font;
}