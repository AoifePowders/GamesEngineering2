#include "Game.h"

Game::Game()
{
	exit = false;
	inputHandler = new InputHandler();
	character = new Character();
	finiteStateMachine = new FSM();
}

Game::~Game()
{
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!" << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		loadTextures();
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else{
		isRunning = false;
	}

	//sets up all positions and width and height of animation
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / 7;
	frameHeight = textureHeight / 21;

	rect.x = rect.y = 0;
	rect.w = frameWidth;
	rect.h = frameHeight;

	positionRect.x = positionRect.y = 0;
	positionRect.w = positionRect.h = 200;
}

void Game::update()
{
	//gets the current state to change animations
	if (finiteStateMachine->getCurrentState() == 0)
	{
		rect.y = 384; // chenges spritesheet animations
	}
	if (finiteStateMachine->getCurrentState() == 1)
	{
		rect.y = 704; 
	}
	if (finiteStateMachine->getCurrentState() == 2)
	{
		rect.y = 64;   
	}

	//animates the sprite sheet
	frameTime++;
	if (FPS / frameTime == 4)
	{
		frameTime = 0;
		rect.x += frameWidth;
		if (rect.x >= textureWidth)
		{
			rect.x = 0;
		}
	}

	if (commandQueue.empty()) {
		finiteStateMachine->idle();
	}
	else
	{
		// Update character state
		while (!commandQueue.empty()) {
			commandQueue.back()->execute(finiteStateMachine);
			commandQueue.pop_back();
		}
	}
}

void Game::handleEvents()
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

	while (!exit) {
		// Handle input
		exit = inputHandler->fill(commandQueue);
		update();
		render();
	}

}

void Game::render()
{
	SDL_RenderClear(renderer);
	//add stuff to render
	SDL_RenderCopy(renderer, texture, &rect, &positionRect);
	SDL_RenderPresent(renderer);	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	IMG_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::running()
{
	return isRunning;
}

//loads the sprite sheet
void Game::loadTextures()
{
	image = IMG_Load("DootToot.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);
}
