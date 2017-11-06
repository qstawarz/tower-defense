#ifndef TOWER_DEFENSE_GAME_H
#define TOWER_DEFENSE_GAME_H

#include "display.h"
#include "interface.h"
#include "field.h"
#include "tower.h"
#include "enemy.h"
#include "player.h"

class Game
{
public:
	Game();
	~Game();
	Game(const Game &);
	Game &operator=(const Game &);
	
	int initGame(void);
	void loopGame(void);
	void endGame(void);

	void drawEverything();
	void doEveryThing();

	void checkInput();
	//PURLPLE TOWER
	bool checkRangePurpleTowerTopEnemy();
	void purpleTowerAttackTopEnemy();
	bool checkRangePurpleTowerBotEnemy();
	void purpleTowerAttackBotEnemy();
	//ORANGE TOWER
	bool checkRangeOrangeTowerTopEnemy();
	void orangeTowerAttackTopEnemy();
	bool checkRangeOrangeTowerBotEnemy();
	void orangeTowerAttackBotEnemy();
	//GREEN TOWER
	bool checkRangeGreenTowerTopEnemy();
	void greenTowerAttackTopEnemy();
	bool checkRangeGreenTowerBotEnemy();
	void greenTowerAttackBotEnemy();

	void putPurpleTower();
	void putOrangeTower();
	void putGreenTower();

protected:

private:
	Display display;

	Interface interface;

	Field field;

	Enemy enemyTop;
	Enemy enemyBot;

	Tower purpleTower;
	Tower orangeTower;
	Tower greenTower;

	Player player;

	bool isTopAlive;
	bool isBotAlive;

	bool isPurpleTower;
	bool isOrangeTower;
	bool isGreenTower;

	static int towerCooldown;

	int gameState;	
	enum state { PAUSE, RUN, GAME_OVER, EXIT };

};

#endif //TOWER_DEFENSE_GAME_H