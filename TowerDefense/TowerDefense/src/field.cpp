#include <iostream>

#include "field.h"

Field::Field()
{
	this->texture = nullptr;
	this->rect = { 0, 0, 0, 0 };
	this->entityState = -1;

	this->grass_texture = nullptr;
	this->dirt_texture = nullptr;
}

Field::~Field()
{
	SDL_DestroyTexture(this->texture);

	SDL_DestroyTexture(this->grass_texture);
	SDL_DestroyTexture(this->dirt_texture);

	std::cout << "Field destroyed" << std::endl;
}

Field::Field(const Field &other)
{
	this->texture = other.texture;
	this->rect = other.rect;
	this->entityState = other.entityState;
}

Field &Field::operator=(const Field &other)
{
	this->texture = other.texture;
	this->rect = other.rect;
	this->entityState = other.entityState;

	return *this;
}

Entity Field::getEntityTab()
{
	return **this->entity_tab;
}

void Field::setFieldRects(SDL_Renderer *renderer)
{
	int i = 0, j = 0;
	while (i < RECT_TAB_X)
	{
		j = 0;
		while (j < RECT_TAB_Y)
		{
			this->entity_tab[i][j].setEntityPos(i * RECT_SIZE_W, j * RECT_SIZE_H, RECT_SIZE_W, RECT_SIZE_H);
			this->entity_tab[i][j].setEntityState(this->entity_tab[i][j].getEntityGrassState());
			this->entity_tab[i][j].loadEntityImg("assets/grass.png", renderer);
			if ((j == 3 && (i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13)) ||
				(j == 4 && (i == 0 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13 || i == 16)) ||
				((j == 5 || j == 6) && (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 6 || i == 7 || i == 9 || i == 10 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16)) ||
				(j == 7 && (i == 0 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 16)) ||
				(j == 8 && (i == 6 || i == 7 || i == 8 || i == 9 || i == 10)))
			{
				this->entity_tab[i][j].setEntityState(this->entity_tab[i][j].getEntityDirtState());
				this->entity_tab[i][j].loadEntityImg("assets/dirt.png", renderer);
			}
			++j;
		}
		++i;
	}
	//TOWER PLACE
	this->entity_tab[5][5].setEntityState(-1);
	this->entity_tab[8][6].setEntityState(-1);
	this->entity_tab[11][5].setEntityState(-1);
}

void Field::drawFieldRects(SDL_Renderer *renderer)
{
	int i = 0, j = 0;
	while (i < RECT_TAB_X)
	{
		j = 0;
		while (j < RECT_TAB_Y)
		{
			if (this->entity_tab[i][j].getEntityState() == this->GRASS)
			{
				SDL_RenderCopy(renderer, &this->entity_tab[i][j].getEntityTexture(), NULL,
					&this->entity_tab[i][j].getEntityPos());

			}
			else if (this->entity_tab[i][j].getEntityState() == this->DIRT)
			{
				SDL_RenderCopy(renderer, &this->entity_tab[i][j].getEntityTexture(), NULL,
					&this->entity_tab[i][j].getEntityPos());
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderDrawRect(renderer, &this->entity_tab[i][j].getEntityPos());
			}
			++j;
		}
		++i;
	}
}

SDL_Texture &Field::getFieldGrassTexture()
{
	return *this->grass_texture;
}

SDL_Texture &Field::getFieldDirtTexture()
{
	return *this->dirt_texture;
}

void Field::loadFieldImg(std::string png, SDL_Texture *texture, SDL_Renderer *renderer)
{
	texture = IMG_LoadTexture(renderer, png.c_str());

	if (texture == NULL)
	{
		std::cout << "Unable to load image:" <<
			SDL_GetError() << std::endl;
	}
}