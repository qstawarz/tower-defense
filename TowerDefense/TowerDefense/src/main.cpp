#include <iostream>

#include "game.h"

int main(int argc, char *args[])
{
	Game game;

	if (game.initGame() == EXIT_SUCCESS)
		game.loopGame();

	//std::cout << "x: " << WINDOW_SIZE_X << " y: " << WINDOW_SIZE_Y << std::endl;

	//SDL_Delay(3 * 1000);

	//system("Pause");

	return EXIT_SUCCESS;
}