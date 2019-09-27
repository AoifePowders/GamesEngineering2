#include "InputHandler.h"

void InputHandler::handleInput()
{
	sf::Event event{};

	if (sf::Event::KeyPressed == event.type) //user pressed a key
	{
		if (sf::Keyboard::Q == event.key.code) { q->execute(); }
		else if (sf::Keyboard::W == event.key.code) { w->execute(); }
		else if (sf::Keyboard::E == event.key.code) { e->execute(); }
		else if (sf::Keyboard::R == event.key.code) { r->execute(); }
		else if (sf::Keyboard::T == event.key.code) { t->execute(); }
		else if (sf::Keyboard::Y == event.key.code) { y->execute(); }
		else if (sf::Keyboard::Tab == event.key.code) { tab->execute(); }
		else if (sf::Keyboard::BackSpace == event.key.code) { backspace->execute(); }
	}
}
