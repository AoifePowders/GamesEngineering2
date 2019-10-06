#pragma once
/// @author Aoife Powders
#include "FSM.h"
#include "FiniteState.h"
#include "Idle.h"

class Jumping : public FiniteState
{
public:
	Jumping();
	~Jumping();
	void idle(FSM* a);
};

