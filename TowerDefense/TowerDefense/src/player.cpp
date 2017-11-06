#include <iostream>

#include "player.h"

Player::Player()
{
	this->player_life = 20;
}

Player::~Player()
{
	std::cout << "Player destroyed" << std::endl;
}

Player::Player(const Player &other)
{
	this->player_life = other.player_life;
}

Player &Player::operator=(const Player &other)
{
	this->player_life = other.player_life;

	return *this;
}

void Player::setPlayerLife(int playe_life)
{
	this->player_life = player_life;
}

int Player::getPlayerLife()
{
	return this->player_life;
}