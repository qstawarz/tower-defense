#ifndef TOWER_DEFENSE_INTERFACE_H
#define TOWER_DEFENSE_INTERFACE_H

#include <SDL.h>
#include <SDL_ttf.h>

class Interface 
{
public:
	Interface();
	~Interface();
	Interface(const Interface &);
	Interface &operator=(const Interface &);

	void setMoney(int);
	void setWave(int);
	void setLife(int);

	int getMoney();
	int getWave();
	int getLife();

	SDL_Rect getMoneyRect();
	SDL_Rect getWaveRect();
	SDL_Rect getLifeRect();

	void displayText(std::string, int, int, int, int, TTF_Font *, SDL_Renderer *);

protected:
	int money;
	int wave;
	int life;

	SDL_Rect money_rect;
	SDL_Rect wave_rect;
	SDL_Rect life_rect;

private:

};

#endif //TOWER_DEFENSE_INTERFACE_H