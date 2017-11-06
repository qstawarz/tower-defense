#include <iostream>
#include <SDL_image.h>

#include "enemy.h"

Enemy::Enemy()
{
	this->enemy_life = 5;
	this->movement_speed = 1;
	this->enemyState = this->RIGHT;

	this->texture = nullptr;
	this->rect = { 0, 0, 0, 0 };
	this->entityState = this->ENEMY;
}

Enemy::~Enemy()
{
	SDL_DestroyTexture(this->texture);

	std::cout << "Enemy destroyed" << std::endl;
}

Enemy::Enemy(const Enemy &other)
{
	this->enemy_life = other.enemy_life;
	this->movement_speed = other.movement_speed;
	this->enemyState = other.enemyState;

	this->texture = other.texture;
	this->rect = other.rect;
	this->entityState = other.entityState;
}

Enemy &Enemy::operator=(const Enemy &other)
{
	this->enemy_life = other.enemy_life;
	this->movement_speed = other.movement_speed;
	this->enemyState = other.enemyState;

	this->texture = other.texture;
	this->rect = other.rect;
	this->entityState = other.entityState;

	return *this;
}

void Enemy::topPathFinding()
{
	if (this->enemyState == this->RIGHT && this->rect.x <= 3 * 64 + 16 && this->rect.y == 5 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 3 * 64 + 16 && this->rect.y == 5 * 64 + 16)
		{
			this->enemyState = this->UP;
		}
	}
	else if (this->enemyState == this->UP && this->rect.y >= 3 * 64 + 16 && this->rect.x == 3 * 64 + 16)
	{
		this->rect.y -= this->movement_speed;
		if (this->rect.y == 3 * 64 + 16 && this->rect.x == 3 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 7 * 64 + 16 && this->rect.y == 3 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 7 * 64 + 16 && this->rect.y == 3 * 64 + 16)
		{
			this->enemyState = this->DOWN;
		}
	}
	else if (this->enemyState == this->DOWN && this->rect.y <= 7 * 64 + 16 && this->rect.x == 7 * 64 + 16)
	{
		this->rect.y += this->movement_speed;
		if (this->rect.y == 7 * 64 + 16 && this->rect.x == 7 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 9 * 64 + 16 && this->rect.y == 7 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 9 * 64 + 16 && this->rect.y == 7 * 64 + 16)
		{
			this->enemyState = this->UP;
		}
	}
	else if (this->enemyState == this->UP && this->rect.y >= 3 * 64 + 16 && this->rect.x == 9 * 64 + 16)
	{
		this->rect.y -= this->movement_speed;
		if (this->rect.y == 3 * 64 + 16 && this->rect.x == 9 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 13 * 64 + 16 && this->rect.y == 3 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 13 * 64 + 16 && this->rect.y == 3 * 64 + 16)
		{
			this->enemyState = this->DOWN;
		}
	}
	else if (this->enemyState == this->DOWN && this->rect.y <= 5 * 64 + 16 && this->rect.x == 13 * 64 + 16)
	{
		this->rect.y += this->movement_speed;
		if (this->rect.y == 5 * 64 + 16 && this->rect.x == 13 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 16 * 64 + 16 && this->rect.y == 5 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 16 * 64 + 16 && this->rect.y == 5 * 64 + 16)
		{
			this->enemyState = this->LEFT;
		}
	}
}

void Enemy::botPathFinding()
{
	if (this->enemyState == this->RIGHT && this->rect.x <= 4 * 64 + 16 && this->rect.y == 6 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 4 * 64 + 16 && this->rect.y == 6 * 64 + 16)
		{
			this->enemyState = this->UP;
		}
	}
	else if (this->enemyState == this->UP && this->rect.y >= 4 * 64 + 16 && this->rect.x == 4 * 64 + 16)
	{
		this->rect.y -= this->movement_speed;
		if (this->rect.y == 4 * 64 + 16 && this->rect.x == 4 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 6 * 64 + 16 && this->rect.y == 4 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 6 * 64 + 16 && this->rect.y == 4 * 64 + 16)
		{
			this->enemyState = this->DOWN;
		}
	}
	else if (this->enemyState == this->DOWN && this->rect.y <= 8 * 64 + 16 && this->rect.x == 6 * 64 + 16)
	{
		this->rect.y += this->movement_speed;
		if (this->rect.y == 8 * 64 + 16 && this->rect.x == 6 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 10 * 64 + 16 && this->rect.y == 8 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 10 * 64 + 16 && this->rect.y == 8 * 64 + 16)
		{
			this->enemyState = this->UP;
		}
	}
	else if (this->enemyState == this->UP && this->rect.y >= 4 * 64 + 16 && this->rect.x == 10 * 64 + 16)
	{
		this->rect.y -= this->movement_speed;
		if (this->rect.y == 4 * 64 + 16 && this->rect.x == 10 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 12 * 64 + 16 && this->rect.y == 4 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 12 * 64 + 16 && this->rect.y == 4 * 64 + 16)
		{
			this->enemyState = this->DOWN;
		}
	}
	else if (this->enemyState == this->DOWN && this->rect.y <= 6 * 64 + 16 && this->rect.x == 12 * 64 + 16)
	{
		this->rect.y += this->movement_speed;
		if (this->rect.y == 6 * 64 + 16 && this->rect.x == 12 * 64 + 16)
		{
			this->enemyState = this->RIGHT;
		}
	}
	else if (this->enemyState == this->RIGHT && this->rect.x <= 16 * 64 + 16 && this->rect.y == 6 * 64 + 16)
	{
		this->rect.x += this->movement_speed;
		if (this->rect.x == 16 * 64 + 16 && this->rect.y == 6 * 64 + 16)
		{
			this->enemyState = this->LEFT;
		}
	}
}

void Enemy::setEnemyLife(int life)
{
	this->enemy_life = life;
}

void Enemy::setEnemySpeed(int speed)
{
	this->movement_speed = speed;
}

void Enemy::setEnemyState(int state)
{
	this->enemyState = state;
}

int Enemy::getEnemyLife()
{
	return this->enemy_life;
}

int Enemy::getEnemySpeed()
{
	return this->movement_speed;
}

int Enemy::getEnemyState()
{
	return this->enemyState;
}

int Enemy::getEnemyRight()
{
	return this->RIGHT;
}