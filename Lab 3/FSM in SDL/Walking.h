#pragma once
/// @author Aoife Powders
#include "FSM.h"
#include "FiniteState.h"
#include "Idle.h"

class Walking : public FiniteState
{
public:
	Walking();
	~Walking();
	void idle(FSM* a);
};
