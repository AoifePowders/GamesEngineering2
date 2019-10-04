#include <iostream>
//abstract factory is a factory that creates 
//related objects without specifying their class
class Character {

public:
	Character() {}
	virtual ~Character() {}
	virtual void draw() = 0;
	virtual void destroy() = 0;
};

class Player : public Character {
public:
	void draw() {
		std::cout << "Draw Player" << std::endl;
	}
	void destroy() {
		std::cout << "Destroy" << std::endl;
		delete this;
	}
};

class Boss : public Character {
public:
	void draw() {
		std::cout << "Draw Boss" << std::endl;
	}
	void destroy() {
		std::cout << "Destroy" << std::endl;
		delete this;
	}
};

//contains virtual functions
class Factory {
public:
	virtual Character* createPlayer() = 0;
	virtual Character* createOpponents() = 0;
};

//virtual functions implemented
//returns pointer to class created
class CharacterFactory : public Factory {
public:
	Character* createPlayer() {
		return new Player;
	}

	Character* createOpponents() {
		return new Boss;
	}
};
