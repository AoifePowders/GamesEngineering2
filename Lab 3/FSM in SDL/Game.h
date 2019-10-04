#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "InputHandler.h"
#include "Character.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

	void update();
	void handleEvents();
	void render();
	void clean();

	bool running();

	InputHandler* inputHandler;
	Character* character;

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool exit;
	std::vector<Command*> commandQueue;

};