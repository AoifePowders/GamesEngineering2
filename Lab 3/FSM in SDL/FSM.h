#pragma once
/// @author Aoife Powders
#include <iostream>
#include <chrono>
#include <thread>

#include "Idle.h"

//calls class state
class FiniteState;
class FSM
{
	class FiniteState* current;

public:

	FSM();

	int getCurrentState();
	//sets the current state
	void setCurrent(FiniteState* s)
	{
		current = s;
	}

	//makes functions
	void idle();
	void walking();
	void jumping();
};



