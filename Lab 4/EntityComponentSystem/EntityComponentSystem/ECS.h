#include <iostream>
#include <map>
#include <vector>
#include "SDL.h"

class Component
{
public:
	int id;

	virtual void thisisherebecauseofreasonsunknown()
	{

	};
};

class Entity
{
private:
	int id;

public:
	Entity() {};
	void addComponents(std::shared_ptr<Component> &c){components.push_back(c);}
	void removeComponent(Component c){}
	std::vector<std::shared_ptr<Component>> getComponent(){return std::vector<std::shared_ptr<Component>> (components);}
private:
	std::vector<std::shared_ptr<Component>> components;

public:
	SDL_Rect rect;
	Uint8 r = 255;
	Uint8 g = 0;
	Uint8 b = 0;
};

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) {};
	int getHealth() { return health; }
	void setHealth(int health) { this->health = health; }
private:
	int health;
};

class HealthSystem
{
	std::vector <Entity> entities;
	std::vector<std::shared_ptr<HealthComponent>> healthptr;
public:
	void addEntity(Entity e) { entities.push_back(e); }

	void init() {
		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i).getComponent().size(); j++)
			{
				if (typeid(*(entities.at(i).getComponent().at(j))) == typeid(HealthComponent))
				{
					healthptr.push_back(std::dynamic_pointer_cast<HealthComponent>(entities.at(i).getComponent().at(j)));
					healthptr.at(i) = std::make_shared<HealthComponent>();
				}
				else
				{
					std::cout << "No Health Component" << std::endl;
				}
			}
		}
	}

	void update() {
		for (int i = 0; i < healthptr.size(); i++)
		{
			std::cout << healthptr.at(i)->getHealth() << std::endl;
		}
	}
};

class PositionComponent : public Component
{
private:
	int xPos = 0;
	int yPos = 0;

public:
	int getXPos() { return xPos; }
	int getYPos() { return yPos; }
	void setPos(int x, int y) { xPos = x; yPos = y; }
};

class PositionSystem
{
	std::vector<Entity> entities;
	std::vector<std::shared_ptr<PositionComponent>> positionptr;
public:
	void addEntity(Entity e) { entities.push_back(e);}

	void init() {
		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i).getComponent().size(); j++)
			{
				if (typeid(*(entities.at(i).getComponent().at(j))) == typeid(PositionComponent))
				{
					positionptr.push_back(std::dynamic_pointer_cast<PositionComponent>(entities.at(i).getComponent().at(j)));
					positionptr.at(i) = std::make_shared<PositionComponent>();
				}
				else
				{
					std::cout << "No Position" << std::endl;
				}
			}
		}

		positionptr.at(0)->setPos(10, 10);
	}

	void update() {
		for (int i = 0; i < positionptr.size(); i++)
		{
			std::cout << positionptr.at(i)->getXPos() << "  " << positionptr.at(i)->getYPos() << std::endl;
		}
	}
};

class RenderSystem
{
	std::vector<Entity> entities;
	std::vector<std::shared_ptr<PositionComponent>> positionptr;

public:
	void addEntity(Entity e) { entities.push_back(e); }

	void draw(SDL_Renderer* render)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			SDL_SetRenderDrawColor(render, entities.at(i).r, entities.at(i).g, entities.at(i).b, 255);
			SDL_RenderFillRect(render, &entities.at(i).rect);
		}
	}

	void init()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i).getComponent().size(); j++)
			{
				if (typeid(*(entities.at(i).getComponent().at(j))) == typeid(PositionComponent))
				{
					positionptr.push_back(std::dynamic_pointer_cast<PositionComponent>(entities.at(i).getComponent().at(j)));
					positionptr.at(i) = std::make_shared<PositionComponent>();
				}
				else
				{
					std::cout << "No Position" << std::endl;
				}
			}
		}

		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i).rect.h = 100;
			entities.at(i).rect.w = 100;
			entities.at(i).rect.x = positionptr.at(i)->getXPos();
			entities.at(i).rect.y = positionptr.at(i)->getYPos();
		}

	}
};

class ControlSystem
{
private:
	std::vector<Entity> entities;
	std::vector<std::shared_ptr<PositionComponent>> positionptr;
	float xpos;
	float ypos = 10;

public:
	void addEntity(Entity e) { entities.push_back(e); }

	void init()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.at(i).getComponent().size(); j++)
			{
				if (typeid(*(entities.at(i).getComponent().at(j))) == typeid(PositionComponent))
				{
					positionptr.push_back(std::dynamic_pointer_cast<PositionComponent>(entities.at(i).getComponent().at(j)));
					positionptr.at(i) = std::make_shared<PositionComponent>();
				}
				else
				{
					std::cout << "No Position" << std::endl;
				}
			}
		}
	}

	void moveRight()
	{
		xpos = positionptr.at(0)->getXPos();
		xpos++;
		positionptr.at(0)->setPos(xpos, ypos);
		std::cout << positionptr.at(0)->getXPos() << std::endl;
	}

	void moveLeft()
	{
		xpos = positionptr.at(0)->getXPos();
		xpos--;
		positionptr.at(0)->setPos(xpos, ypos);
	}
};
