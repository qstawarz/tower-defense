#ifndef TOWER_DEFENSE_TOWER_H
#define TOWER_DEFENSE_TOWER_H

#define TOWER_SIZE_W 50
#define TOWER_SIZE_H 50

#include "entity.h"

class Tower : public Entity
{
public:
	Tower();
	~Tower();
	Tower(const Tower &);
	Tower &operator=(const Tower &);

	void setTowerDamage(int);
	void setTowerSpeed(int);
	void setTowerRadius(int);

	int getTowerDamage();
	int getTowerSpeed();
	int getTowerRadius();

protected:
	int damage;
	int attack_speed;
	int radius;

private:

};

#endif //TOWER_DEFENSE_TOWER_H