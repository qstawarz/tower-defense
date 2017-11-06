#include <iostream>

#include "entity.h"

Entity::Entity()
{
	this->texture = nullptr;

	this->rect = { 0, 0, 0, 0 };

	this->entityState = -1;
}

Entity::~Entity()
{
	SDL_DestroyTexture(this->texture);

	std::cout << "Entity destroyed" << std::endl;
}

Entity::Entity(const Entity &other)
{
	this->texture = other.texture;

	this->rect = other.rect;

	this->entityState = other.entityState;
}

Entity &Entity::operator=(const Entity &other)
{
	this->texture = other.texture;

	this->rect = other.rect;

	this->entityState = other.entityState;

	return *this;
}

void Entity::setEntityPos(int x, int y, int h, int w)
{
	this->rect.x = x;
	this->rect.y = y;
	this->rect.h = h;
	this->rect.w = w;
}

SDL_Rect Entity::getEntityPos()
{
	return this->rect;
}

void Entity::setEntityPosX(int x)
{
	this->rect.x = x;
}

void Entity::setEntityPosY(int y)
{
	this->rect.x = y;
}

int Entity::getEntityPosX()
{
	return this->rect.x;
}

int Entity::getEntityPosY()
{
	return this->rect.y;
}

void Entity::setEntityState(int cellState)
{
	this->entityState = cellState;
}

int Entity::getEntityState()
{
	return this->entityState;
}

int Entity::getEntityGrassState()
{
	return this->GRASS;
}

int Entity::getEntityDirtState()
{
	return this->DIRT;
}

SDL_Texture &Entity::getEntityTexture()
{
	return *this->texture;
}

void Entity::loadEntityImg(std::string png, SDL_Renderer *renderer)
{
	this->texture = IMG_LoadTexture(renderer, png.c_str());

	if (this->texture == NULL)
	{
		std::cout << "Unable to load image:" <<
			SDL_GetError() << std::endl;
	}
}

void Entity::drawEntityRect(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer,
		this->texture, NULL,
		&this->rect);
}