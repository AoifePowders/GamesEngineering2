#include <iostream>
#include "Command.h"
#include "SFML/Graphics.hpp"

class InputHandler
{
public:
	void handleInput();

private:
	Command* q;
	Command* w;
	Command* e;
	Command* r;
	Command* t;
	Command* y;
	Command* tab;
	Command* backspace;
};

