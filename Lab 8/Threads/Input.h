#pragma once
class Input
{
public:
	void update(sf::Vector2f& position);
};

void Input::update(sf::Vector2f& position)
{
	std::cout << "Input Thread" << std::endl;
	position.x += 1;
	position.y += 1;
}
