#include <iostream>

#include "game.h"

int Game::towerCooldown = 50;

Game::Game()
{
	this->isTopAlive = false;
	this->isBotAlive = false;

	this->isPurpleTower = false;
	this->isOrangeTower = false;
	this->isGreenTower = false;
}

Game::~Game()
{
	std::cout << "Game destroyed" << std::endl;
}

Game::Game(const Game &other)
{

}

Game &Game::operator=(const Game &other)
{
	return *this;
}

int Game::initGame(void)
{
	//initialisation SDL, window, renderer, font
	this->display.initAll();

	//set Field Position
	this->field.setFieldRects(&this->display.getRenderer());
	//load Field Image
	this->field.loadFieldImg("assets/grass.png", &this->field.getFieldGrassTexture(), &this->display.getRenderer());
	this->field.loadFieldImg("assets/dirt.png", &this->field.getFieldDirtTexture(), &this->display.getRenderer());

	//set Enemy Position
	this->enemyTop.setEntityPos(0 * 64 + 16, 5 * 64 + 16, ENEMY_SIZE_H, ENEMY_SIZE_W);
	this->enemyBot.setEntityPos(0 * 64 + 16, 6 * 64 + 16, ENEMY_SIZE_H, ENEMY_SIZE_W);
	//load Enemy Image
	this->enemyTop.loadEntityImg("assets/red_enemy.png", &this->display.getRenderer());
	this->enemyBot.loadEntityImg("assets/red_enemy.png", &this->display.getRenderer());
	//set Enemy Alive
	this->isTopAlive = true;
	this->isBotAlive = true;

	this->gameState = this->RUN;

	return EXIT_SUCCESS;
}

void Game::loopGame()
{
	Uint32 start;
	int currentTime;

	while (this->gameState == this->RUN)
	{
		start = SDL_GetTicks();

		this->display.clearRenderer();

		this->drawEverything();
			
		this->display.presentRenderer();

		this->doEveryThing();

		currentTime = SDL_GetTicks() - start;
		if (FRAME_DELAY > currentTime)
		{
			SDL_Delay(FRAME_DELAY - currentTime);
		}

		if (this->gameState == this->EXIT)
		{
			this->endGame();
		}
		if (this->gameState == this->GAME_OVER)
		{
			this->display.clearRenderer();
			this->interface.displayText("GAME OVER", WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2, 0, 0,
				&this->display.getFont(), &this->display.getRenderer());
			this->display.presentRenderer();
			SDL_Delay(1 * 1000);
		}
	}
}

void Game::endGame()
{
	
}

void Game::drawEverything()
{
	//FIELD
	this->field.drawFieldRects(&this->display.getRenderer());
	//TOP ENEMY
	if (enemyTop.getEnemyLife() > 0 && enemyTop.getEntityPos().x < 16 * 64 + 16)
	{
		this->enemyTop.drawEntityRect(&this->display.getRenderer());
		this->interface.displayText(std::to_string(this->enemyTop.getEnemyLife()), this->enemyTop.getEntityPosX() + 75,
			this->enemyTop.getEntityPosY() - 20, 7, 45, &this->display.getFont(), &this->display.getRenderer());
	}
	if (enemyTop.getEnemyLife() <= 0)
	{
		this->interface.setMoney(this->interface.getMoney() + 25);
		this->interface.setWave(this->interface.getWave() + 1);
		this->enemyTop.setEntityPos(0 * 64 + 16, 5 * 64 + 16, ENEMY_SIZE_H, ENEMY_SIZE_W);
		//this->enemyTop.loadEntityImg("assets/blue_enemy.png", &this->display.getRenderer());
		this->enemyTop.setEnemyLife(5);
		this->enemyTop.setEnemyState(this->enemyTop.getEnemyRight());
	}
	if (enemyTop.getEntityPos().x == 16 * 64 + 16)
	{
		if (this->interface.getLife() <= 0)
		{
			this->gameState = this->GAME_OVER;
		}
		else
		{
			this->interface.setLife(this->interface.getLife() - 1);
			this->interface.setWave(this->interface.getWave() + 1);
			this->enemyTop.setEntityPos(0 * 64 + 16, 5 * 64 + 16, ENEMY_SIZE_H, ENEMY_SIZE_W);
			//this->enemyTop.loadEntityImg("assets/blue_enemy.png", &this->display.getRenderer());
			this->enemyTop.setEnemyLife(5);
			this->enemyTop.setEnemyState(this->enemyTop.getEnemyRight());
		}
	}
	//BOT ENEMY
	if (enemyBot.getEnemyLife() > 0 && enemyBot.getEntityPos().x < 16 * 64 + 16)
	{
		this->enemyBot.drawEntityRect(&this->display.getRenderer());
		this->interface.displayText(std::to_string(this->enemyBot.getEnemyLife()), this->enemyBot.getEntityPosX() + 75, 
			this->enemyBot.getEntityPosY() - 20, 7, 45, &this->display.getFont(), &this->display.getRenderer());
	}
	if (enemyBot.getEnemyLife() <= 0)
	{
		this->interface.setMoney(this->interface.getMoney() + 25);
		this->interface.setWave(this->interface.getWave() + 1);
		this->enemyBot.setEntityPos(0 * 64 + 16, 6 * 64 + 16, ENEMY_SIZE_H, ENEMY_SIZE_W);
		//this->enemyBot.loadEntityImg("assets/blue_enemy.png", &this->display.getRenderer());
		this->enemyBot.setEnemyLife(5);
		this->enemyBot.setEnemyState(this->enemyBot.getEnemyRight());
	}
	if (enemyBot.getEntityPos().x == 16 * 64 + 16)
	{
		if (this->interface.getLife() <= 0)
		{
			this->gameState = this->GAME_OVER;
		}
		else
		{
			this->interface.setLife(this->interface.getLife() - 1);
			this->interface.setWave(this->interface.getWave() + 1);
			this->enemyBot.setEntityPos(0 * 64 + 16, 6 * 64 + 16, ENEMY_SIZE_H, ENEMY_SIZE_W);
			//this->enemyBot.loadEntityImg("assets/blue_enemy.png", &this->display.getRenderer());
			this->enemyBot.setEnemyLife(5);
			this->enemyBot.setEnemyState(this->enemyBot.getEnemyRight());
		}
	}
	//TOWERS
	this->purpleTower.drawEntityRect(&this->display.getRenderer());
	this->orangeTower.drawEntityRect(&this->display.getRenderer());
	this->greenTower.drawEntityRect(&this->display.getRenderer());
	//INTERFACE
	this->interface.displayText("MONEY : " + std::to_string(this->interface.getMoney()), 
		3 * 64 / 2, 1 * 64 / 2, 0, 0, &this->display.getFont(), &this->display.getRenderer());
	this->interface.displayText("WAVE : " + std::to_string(this->interface.getWave()), 
		WINDOW_SIZE_X / 2, 1 * 64 / 2, 0, 0, &this->display.getFont(), &this->display.getRenderer());
	this->interface.displayText("LIFE : " + std::to_string(this->interface.getLife()), 
		32 * 64 / 2, 1 * 64 / 2, 0, 0, &this->display.getFont(), &this->display.getRenderer());
}

void Game::doEveryThing()
{
	//TOP AND BOT ENEMY
	if (this->isTopAlive == true && this->isBotAlive == true)
	{
		this->enemyTop.topPathFinding();
		this->enemyBot.botPathFinding();
	}
	//PURPLE TOWER
	if (this->checkRangePurpleTowerTopEnemy() == true)
	{
		this->purpleTowerAttackTopEnemy();
	}
	if (this->checkRangePurpleTowerBotEnemy() == true)
	{
		this->purpleTowerAttackBotEnemy();
	}
	//ORANGE TOWER
	if (this->checkRangeOrangeTowerTopEnemy() == true)
	{
		this->orangeTowerAttackTopEnemy();
	}
	if (this->checkRangeOrangeTowerBotEnemy() == true)
	{
		this->orangeTowerAttackBotEnemy();
	}
	//GREEN TOWER
	if (this->checkRangeGreenTowerTopEnemy() == true)
	{
		this->greenTowerAttackTopEnemy();
	}
	if (this->checkRangeGreenTowerBotEnemy() == true)
	{
		this->greenTowerAttackBotEnemy();
	}

	this->checkInput();
	SDL_PumpEvents();
}

void Game::checkInput()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT :
			this->gameState = this->EXIT;
			break;
		case SDL_KEYDOWN :
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				this->gameState = this->EXIT;
				break;
			case SDLK_p:
				this->gameState = this->PAUSE;
			default:
				break;
			}
		}
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			int x = 0, y = 0;
			SDL_GetMouseState(&x, &y);
			if (((x > 5 * 64 && x < 5 * 64 + 64) && (y > 5 * 64 && y < 5 * 64 + 64)) && 
				this->isPurpleTower == false && this->interface.getMoney() >= 75)
			{
				this->putPurpleTower();
				this->interface.setMoney(this->interface.getMoney() - 75);
			}
			if (((x > 8 * 64 && x < 8 * 64 + 64) && (y > 6 * 64 && y < 6 * 64 + 64)) && 
				this->isOrangeTower == false && this->interface.getMoney() >= 75)
			{
				this->putOrangeTower();
				this->interface.setMoney(this->interface.getMoney() - 75);
			}
			if (((x > 11 * 64 && x < 11 * 64 + 64) && (y > 5 * 64 && y < 5 * 64 + 64)) && 
				this->isGreenTower == false && this->interface.getMoney() >= 75)
			{
				this->putGreenTower();
				this->interface.setMoney(this->interface.getMoney() - 75);
			}
		}
	}
}
//PURPLE TOWER
bool Game::checkRangePurpleTowerTopEnemy()
{
	int range = sqrt(pow((this->enemyTop.getEntityPos().x + 12) - (this->purpleTower.getEntityPos().x + 32), 2) + 
		pow((this->enemyTop.getEntityPos().y + 12) - (this->purpleTower.getEntityPos().y + 32), 2));
	int rangeMin = this->enemyTop.getEntityPos().w + this->purpleTower.getTowerRadius() * 
		this->enemyTop.getEntityPos().h + this->purpleTower.getTowerRadius();

	if (range <= rangeMin)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::purpleTowerAttackTopEnemy()
{
	--this->towerCooldown;
	
	if (this->towerCooldown == 0)
	{
		this->enemyTop.setEnemyLife(this->enemyTop.getEnemyLife() - this->purpleTower.getTowerDamage());
		this->towerCooldown = 50;
	}
}

bool Game::checkRangePurpleTowerBotEnemy()
{
	int range = sqrt(pow((this->enemyBot.getEntityPos().x + 12) - (this->purpleTower.getEntityPos().x + 32), 2) + 
		pow((this->enemyBot.getEntityPos().y + 12) - (this->purpleTower.getEntityPos().y + 32), 2));
	int rangeMin = this->enemyBot.getEntityPos().w + this->purpleTower.getTowerRadius() * 
		this->enemyBot.getEntityPos().h + this->purpleTower.getTowerRadius();

	if (range <= rangeMin)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::purpleTowerAttackBotEnemy()
{
	--this->towerCooldown;

	if (this->towerCooldown == 0)
	{
		this->enemyBot.setEnemyLife(this->enemyBot.getEnemyLife() - this->purpleTower.getTowerDamage());
		this->towerCooldown = 50;
	}
}

//ORANGE TOWER
bool Game::checkRangeOrangeTowerTopEnemy()
{
	int range = sqrt(pow((this->enemyTop.getEntityPos().x + 12) - (this->orangeTower.getEntityPos().x + 32), 2) + 
		pow((this->enemyTop.getEntityPos().y + 12) - (this->orangeTower.getEntityPos().y + 32), 2));
	int rangeMin = this->enemyTop.getEntityPos().w + this->orangeTower.getTowerRadius() * 
		this->enemyTop.getEntityPos().h + this->orangeTower.getTowerRadius();

	if (range <= rangeMin)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::orangeTowerAttackTopEnemy()
{
	--this->towerCooldown;

	if (this->towerCooldown == 0)
	{
		this->enemyTop.setEnemyLife(this->enemyTop.getEnemyLife() - this->orangeTower.getTowerDamage());
		this->towerCooldown = 50;
	}
}

bool Game::checkRangeOrangeTowerBotEnemy()
{
	int range = sqrt(pow((this->enemyBot.getEntityPos().x + 12) - (this->orangeTower.getEntityPos().x + 32), 2) + 
		pow((this->enemyBot.getEntityPos().y + 12) - (this->orangeTower.getEntityPos().y + 32), 2));
	int rangeMin = this->enemyBot.getEntityPos().w + this->orangeTower.getTowerRadius() * 
		this->enemyBot.getEntityPos().h + this->orangeTower.getTowerRadius();

	if (range <= rangeMin)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::orangeTowerAttackBotEnemy()
{
	--this->towerCooldown;

	if (this->towerCooldown == 0)
	{
		this->enemyBot.setEnemyLife(this->enemyBot.getEnemyLife() - this->orangeTower.getTowerDamage());
		this->towerCooldown = 50;
	}
}
//GREEN TOWER
bool Game::checkRangeGreenTowerTopEnemy()
{
	int range = sqrt(pow((this->enemyTop.getEntityPos().x + 12) - (this->greenTower.getEntityPos().x + 32), 2) + 
		pow((this->enemyTop.getEntityPos().y + 12) - (this->greenTower.getEntityPos().y + 32), 2));
	int rangeMin = this->enemyTop.getEntityPos().w + this->greenTower.getTowerRadius() * 
		this->enemyTop.getEntityPos().h + this->greenTower.getTowerRadius();

	if (range <= rangeMin)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::greenTowerAttackTopEnemy()
{
	--this->towerCooldown;

	if (this->towerCooldown == 0)
	{
		this->enemyTop.setEnemyLife(this->enemyTop.getEnemyLife() - this->greenTower.getTowerDamage());
		this->towerCooldown = 50;
	}
}

bool Game::checkRangeGreenTowerBotEnemy()
{
	int range = sqrt(pow((this->enemyBot.getEntityPos().x + 12) - (this->greenTower.getEntityPos().x + 32), 2) + 
		pow((this->enemyBot.getEntityPos().y + 12) - (this->greenTower.getEntityPos().y + 32), 2));
	int rangeMin = this->enemyBot.getEntityPos().w + this->greenTower.getTowerRadius() * 
		this->enemyBot.getEntityPos().h + this->greenTower.getTowerRadius();

	if (range <= rangeMin)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::greenTowerAttackBotEnemy()
{
	--this->towerCooldown;

	if (this->towerCooldown == 0)
	{
		this->enemyBot.setEnemyLife(this->enemyBot.getEnemyLife() - this->greenTower.getTowerDamage());
		this->towerCooldown = 50;
	}
}

void Game::putPurpleTower()
{
	this->purpleTower.setEntityPos(5 * 64 + 8, 5 * 64 + 8, TOWER_SIZE_H, TOWER_SIZE_W);
	this->purpleTower.loadEntityImg("assets/purple_tower.png", &this->display.getRenderer());
	this->isPurpleTower = true;
}

void Game::putOrangeTower()
{
	this->orangeTower.setEntityPos(8 * 64 + 8, 6 * 64 + 8, TOWER_SIZE_H, TOWER_SIZE_W);
	this->orangeTower.loadEntityImg("assets/orange_tower.png", &this->display.getRenderer());
	this->isOrangeTower = true;
}

void Game::putGreenTower()
{
	this->greenTower.setEntityPos(11 * 64 + 8, 5 * 64 + 8, TOWER_SIZE_H, TOWER_SIZE_W);
	this->greenTower.loadEntityImg("assets/green_tower.png", &this->display.getRenderer());
	this->isGreenTower = true;
}