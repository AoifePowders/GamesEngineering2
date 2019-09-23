#include <iostream>

class CharacterTwo
{
public:
	CharacterTwo() {}
	void Print() { std::cout << "Printing Charcater" << std::endl; }
};

class HandleToCharacter
{
public:
	HandleToCharacter() : character(new CharacterTwo()) {}
	CharacterTwo* operator->() { return character; }//overloaded -> function

private:
	CharacterTwo* character;
};