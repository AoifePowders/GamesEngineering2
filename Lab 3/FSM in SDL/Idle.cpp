#include "Idle.h"
/// @author Aoife Powders

Idle::Idle()
{
}


Idle::~Idle()
{
}


void Idle::walking(FSM* a)
{
	std::cout << "Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

void Idle::jumping(FSM* a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}