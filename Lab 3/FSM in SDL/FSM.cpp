#include "FSM.h"
/// @author Aoife Powders

//define functions using polymorphism
FSM::FSM()
{
	current = new Idle();
}

int FSM::getCurrentState()
{
	return current->currentState;
}

void FSM::idle()
{
	current->idle(this);
}

void FSM::walking()
{
	current->walking(this);
}

void FSM::jumping()
{
	current->jumping(this);
}



