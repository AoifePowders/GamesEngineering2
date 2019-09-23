#include <iostream>
#include <vector>
#include "AbstractFactory.h"
#include "BridgePattern.h"
#include "HandleClass.h"
#include "Proxy.h"

int main() {

	//ABSTRACT FACTORY
	Factory* factory = new CharacterFactory;
	std::vector<Character*> characters;
	characters.push_back(factory->createPlayer());
	characters.push_back(factory->createOpponents());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
		characters[i]->destroy();
	}
	characters[0]->draw();
	//HANDLE CLASS
	//BRIDGE PATTERN

	HandleToCharacter handle;
	handle->Print();

	//BRIDGE PATTERN
	DrawAPI* api = new DrawImpl();
	CharacterThree* character = new PlayerTwo(api);
	character->Draw();
	character->destroy();
	std::cin.get();

	//PROXY IMPLEMETATION
	//Client(Implementaion)
	GraphicProxy gp;
	gp.Draw();
}