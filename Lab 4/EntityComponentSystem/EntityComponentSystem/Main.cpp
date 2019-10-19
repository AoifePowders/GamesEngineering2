#include "SDL.h"
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();

	game->init("ECS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {
		game->processEvents();
		game->update();
		game->render();
	}
	game->cleanUp();
	return 0;
}