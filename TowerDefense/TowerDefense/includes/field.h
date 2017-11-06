#ifndef TOWER_DEFENSE_FIELD_H
#define TOWER_DEFENSE_FIELD_H

#include <SDL.h>
#include <SDL_image.h>
//#include "manager.h" //Window_size info
#include "entity.h"

#define RECT_SIZE_W 64
#define RECT_SIZE_H 64
#define RECT_TAB_X 17 //(WINDOW_SIZE_X / RECT_SIZE_W)
#define RECT_TAB_Y 12 //(WINDOW_SIZE_Y / RECT_SIZE_H)


class Field : public Entity
{
public:
	Field();
	~Field();
	Field(const Field &);
	Field &operator=(const Field &);

	Entity getEntityTab();

	void setFieldRects(SDL_Renderer *);
	void drawFieldRects(SDL_Renderer *);

	SDL_Texture &getFieldGrassTexture();
	SDL_Texture &getFieldDirtTexture();

	void loadFieldImg(std::string, SDL_Texture *, SDL_Renderer *);

protected:

private:
	SDL_Texture *grass_texture;
	SDL_Texture *dirt_texture;
	Entity entity_tab[RECT_TAB_X][RECT_TAB_Y];

};

#endif //TOWER_DEFENSE_FIELD_H