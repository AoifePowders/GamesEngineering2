#pragma once
class Game
{
public:
	void update(sf::Vector2f &position);
};

void Game::update(sf::Vector2f& position)
{
	std::cout << "Game Thread" << std::endl;
	position.x += 1;
	position.y += 1;
}

