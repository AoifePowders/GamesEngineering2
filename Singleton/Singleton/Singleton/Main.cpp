#include <iostream>
#include "Singleton.h"

int main()
{
	//create singleton
	Singleton* s = Singleton::getInstance();
	Singleton* r = Singleton::getInstance();

	//The memory addresses will be the same
	std::cout << s << std::endl;
	std::cout << r << std::endl;

	system("Pause");
	return 0;
}