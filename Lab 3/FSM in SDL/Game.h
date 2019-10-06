#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "InputHandler.h"
#include "Character.h"
#include "FSM.h"

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
	void loadTextures();

	InputHandler* inputHandler;
	Character* character;
	FSM* finiteStateMachine;

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool exit;
	std::vector<Command*> commandQueue;

	SDL_Surface* image;
	SDL_Texture* texture;

	SDL_Rect rect;
	SDL_Rect positionRect;

	int textureWidth;
	int textureHeight;
	int frameWidth;
	int frameHeight;

	const int FPS = 60;
	int frameTime = 0;
};