#ifndef TOWER_DEFENSE_ENTITY_H
#define TOWER_DEFENSE_ENTITY_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Entity
{
public:
	Entity();
	~Entity();
	Entity(const Entity &);
	Entity &operator=(const Entity &);

	void setEntityPos(int, int, int, int);
	SDL_Rect getEntityPos();

	void setEntityPosX(int);
	void setEntityPosY(int);
	int getEntityPosX();
	int getEntityPosY();

	void setEntityState(int);
	int getEntityState();
	int getEntityGrassState();
	int getEntityDirtState();

	SDL_Texture &getEntityTexture();

	void loadEntityImg(std::string, SDL_Renderer *);
	void drawEntityRect(SDL_Renderer *);

protected:
	SDL_Texture *texture;
	SDL_Rect rect;

	int entityState;

	enum entity_state { GRASS, DIRT, ENEMY, TOWER };

private:

};

#endif //TOWER_DEFENSE_ENTITY_H