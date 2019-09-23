#include <iostream>

class DrawAPI
{
public:
	virtual void Draw() = 0;
	virtual void destroy() = 0;
};

class DrawImpl : public DrawAPI
{
public:
	void Draw() { std::cout << "Draw Impl" << std::endl; }
	void destroy() { std::cout << "Destroy" << std::endl; }
};

class CharacterThree
{
public: 
	virtual void Draw() = 0;
	virtual void destroy() = 0;
};

class PlayerTwo : public CharacterThree
{
public:
	PlayerTwo(DrawAPI* api) { this->api = api; }
	void Draw() { api->Draw(); }
	void destroy() { api->destroy(), delete api; }

private:
	DrawAPI* api;
};

