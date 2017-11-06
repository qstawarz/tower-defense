#ifndef TOWER_DEFENSE_ENEMY_H
#define TOWER_DEFENSE_ENEMY_H

#define ENEMY_SIZE_W 25
#define ENEMY_SIZE_H 25

#include "entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();
	Enemy(const Enemy &);
	Enemy &operator=(const Enemy &);

	void topPathFinding();
	void botPathFinding();

	void setEnemyLife(int);
	void setEnemySpeed(int);
	void setEnemyState(int);

	int getEnemyLife();
	int getEnemySpeed();
	int getEnemyState();

	int getEnemyRight();

protected:

private:
	int enemy_life;
	int movement_speed;
	int enemyState;

	enum state { LEFT, RIGHT, UP, DOWN };

};

#endif //TOWER_DEFENSE_ENEMY_H