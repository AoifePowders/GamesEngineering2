#ifndef GAME
#define GAME

#include <SDL.h>
#include <iostream>

#include "ECS.h"
#include <string>


class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void update();

	void processEvents();
	void render();
	void cleanUp();

	bool running() { return isRunning; }

	//shared pointer?
	Entity* player = new Entity();
	Entity* dog = new Entity();
	Entity* cat = new Entity();
	Entity* alien = new Entity();

	//Component
	std::shared_ptr<Component> hc = std::make_shared<HealthComponent>();
	std::shared_ptr<Component> pc = std::make_shared<PositionComponent>();

	//system
	HealthSystem hs;
	PositionSystem ps;
	RenderSystem rs;
	ControlSystem cs;



private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	bool m_exitGame;

};

#endif // !GAME
