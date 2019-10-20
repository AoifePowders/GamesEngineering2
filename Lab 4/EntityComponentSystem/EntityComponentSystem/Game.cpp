#include "Game.h"

Game::Game()
{
	m_exitGame = false;
}


Game::~Game()
{
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << " Subsystem initialised!!" << std::endl;
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

		if (window)
		{
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0 | SDL_RENDERER_PRESENTVSYNC);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	player->addComponents(hc);
	hs.addEntity(*player);
	//dog->addComponents(hc);
	//hs.addEntity(*dog);
	//alien->addComponents(hc);
	//hs.addEntity(*alien);
	hs.init();

	player->addComponents(pc);
	ps.addEntity(*player);
	//cat->addComponents(pc);
	//ps.addEntity(*cat);
	//dog->addComponents(pc);
	//ps.addEntity(*dog);
	//alien->addComponents(pc);
	//ps.addEntity(*alien);
	ps.init();

	rs.addEntity(*player);
	//rs.addEntity(*cat);
	//rs.addEntity(*dog);
	//rs.addEntity(*alien);
	rs.init();

	cs.addEntity(*player);
	cs.init();
}

void Game::processEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	switch (event.type) {
		switch (event.key.keysym.sym) {
		case SDLK_a:
			cs.moveLeft();
			break;
		case SDLK_d:
			cs.moveRight();
			break;
		case SDLK_UP:
			break;
		case SDLK_DOWN:
			break;
		default:
			break;
		}
	}


	while (!m_exitGame) {
		update();
		render();
	}
}

void Game::update()
{
	hs.update();
	ps.update();

	//system("CLS");
}

/// draw the frame and then switch bufers
void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//Clears image after every frame
	SDL_RenderClear(renderer);
	rs.draw(renderer);
	SDL_RenderPresent(renderer);
}

void Game::cleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	window = nullptr;
	renderer = nullptr;

	SDL_Quit();
	std::cout << "Cleaned" << std::endl;

}
