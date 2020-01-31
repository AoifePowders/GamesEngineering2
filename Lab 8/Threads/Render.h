#pragma once
class Render
{
public:
	void update(sf::Vector2f& position);
};

void Render::update(sf::Vector2f& position)
{
	std::cout << "Render Thread" << std::endl;
	position.x += 1;
	position.y += 1;
}
