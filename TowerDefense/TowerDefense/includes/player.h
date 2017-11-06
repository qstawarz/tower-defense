#ifndef TOWER_DEFENSE_PLAYER_H
#define TOWER_DEFENSE_PLAYER_H

class Player
{
public:
	Player();
	~Player();
	Player(const Player &);
	Player &operator=(const Player &);

	void setPlayerLife(int);
	int getPlayerLife();

protected:
	int player_life;

private:

};

#endif //TOWER_DEFENSE_PLAYER_H