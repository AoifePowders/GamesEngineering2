#include "InputHandler.h"

void InputHandler::handleInput(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type) //user pressed a key
	{
		if (sf::Keyboard::Q == t_event.key.code) { q->execute(); std::cout << "pressed"; }
		else if (sf::Keyboard::W == t_event.key.code) { w->execute(); }
		else if (sf::Keyboard::E == t_event.key.code) { e->execute(); }
		else if (sf::Keyboard::R == t_event.key.code) { r->execute(); }
		else if (sf::Keyboard::T == t_event.key.code) { t->execute(); }
		else if (sf::Keyboard::Y == t_event.key.code) { y->execute(); }
		else if (sf::Keyboard::Tab == t_event.key.code) { tab->execute(); }
		else if (sf::Keyboard::BackSpace == t_event.key.code) { backspace->execute(); }
	}
}
