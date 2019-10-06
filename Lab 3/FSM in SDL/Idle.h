#pragma once
/// @author Aoife Powders
#include "FSM.h"
#include "FiniteState.h"
#include "Jumping.h"
#include "Walking.h"

//creates a class of public state
class Idle : public FiniteState
{
public:
	Idle();
	~Idle();
	void walking(FSM* a);
	void jumping(FSM* a);
};