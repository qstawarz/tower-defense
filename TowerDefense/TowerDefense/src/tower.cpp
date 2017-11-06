#include <iostream>

#include "tower.h"

Tower::Tower()
{
	this->damage = 1;
	this->attack_speed = 1;
	this->radius = 3;

	this->texture = nullptr;
	this->rect = { 0, 0, 0, 0 };
	this->entityState = this->TOWER;
}

Tower::~Tower()
{
	SDL_DestroyTexture(this->texture);

	std::cout << "Tower destroyed" << std::endl;
}

Tower::Tower(const Tower &other)
{
	this->damage = other.damage;
	this->attack_speed = other.attack_speed;
	this->radius = other.radius;

	this->texture = other.texture;
	this->rect = other.rect;
	this->entityState = other.entityState;
}

Tower &Tower::operator=(const Tower &other)
{
	this->damage = other.damage;
	this->attack_speed = other.attack_speed;
	this->radius = other.radius;

	this->texture = other.texture;
	this->rect = other.rect;
	this->entityState = other.entityState;

	return *this;
}

void Tower::setTowerDamage(int damage)
{
	this->damage = damage;
}

void Tower::setTowerSpeed(int speed)
{
	this->attack_speed = speed;
}

void Tower::setTowerRadius(int radius)
{
	this->radius = radius;
}

int Tower::getTowerDamage()
{
	return this->damage;
}

int Tower::getTowerSpeed()
{
	return this->attack_speed;
}

int Tower::getTowerRadius()
{
	return this->radius;
}