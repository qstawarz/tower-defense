#include <iostream>
#include <string>

#include "interface.h"

Interface::Interface()
{
	this->money = 100;
	this->wave = 1;
	this->life = 20;

	this->money_rect = { 1 * 64, 1 * 64, 10, 10 };
	this->wave_rect = { 8 * 64, 1 * 64, 100, 100 };
	this->life_rect = { 15 * 64, 1 * 64, 100, 100 };
}

Interface::~Interface()
{
	std::cout << "Interface destroyed" << std::endl;
}

Interface::Interface(const Interface &other)
{
	this->money = other.money;
	this->wave = other.wave;
	this->life = other.life;

	this->money_rect = other.money_rect;
	this->wave_rect = other.wave_rect;
	this->life_rect = other.life_rect;
}

Interface &Interface::operator=(const Interface &other)
{
	this->money = other.money;
	this->wave = other.wave;
	this->life = other.life;

	this->money_rect = other.money_rect;
	this->wave_rect = other.wave_rect;
	this->life_rect = other.life_rect;

	return *this;
}

void Interface::setMoney(int money)
{
	this->money = money;
}

void Interface::setWave(int score)
{
	this->wave = score;
}

void Interface::setLife(int life)
{
	this->life = life;
}

int Interface::getMoney()
{
	return this->money;
}

int Interface::getWave()
{
	return this->wave;
}

int Interface::getLife()
{
	return this->life;
}

SDL_Rect Interface::getMoneyRect()
{
	return this->money_rect;
}

SDL_Rect Interface::getWaveRect()
{
	return this->wave_rect;
}

SDL_Rect Interface::getLifeRect()
{
	return this->life_rect;
}

void Interface::displayText(std::string str, int x, int y, int w, int h, TTF_Font *font, SDL_Renderer *renderer)
{
	SDL_Color white = { 255, 255, 255, 255 };

	SDL_Surface* surface = TTF_RenderUTF8_Solid(font, str.c_str(), white);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	int surface_w, surface_h;
	SDL_QueryTexture(texture, NULL, NULL, &surface_w, &surface_h);

	SDL_Rect rect = { x - surface_h, y, surface_w - w, surface_h - h };

	SDL_RenderCopy(renderer, texture, NULL, &rect);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}