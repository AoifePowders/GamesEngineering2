#include <iostream>
//bridge pattern is meant to decouple abstraction.
//similar to the abstract factory but the implementation
//of fuctions is placed in a different class.

//drawapi is the bridge connecting the fuction inplementeation to the class
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

