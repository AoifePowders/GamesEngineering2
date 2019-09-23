#include <iostream>

class Singleton
{
private:
	//store instance
	static Singleton* instance;
	//constructor
	Singleton();

public:
	//access the instance
	static Singleton* getInstance();
};

Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
	if (instance == 0)
	{
		instance = new Singleton();
	}

	return instance;
}

Singleton::Singleton()
{}
