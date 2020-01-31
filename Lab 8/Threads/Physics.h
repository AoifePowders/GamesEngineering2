#pragma once
class Physics
{
public:
	void update(sf::Vector2f& position);
};

void Physics::update(sf::Vector2f& position)
{
	std::cout << "Physics Thread" << std::endl;
	position.x += 1;
	position.y += 1;
}
