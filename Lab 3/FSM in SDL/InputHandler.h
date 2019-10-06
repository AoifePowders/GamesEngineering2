#include <map>
#include <vector>
#include <SDL.h>
#include "character.h"
#include "FSM.h"

enum InputType
{
	ACTION,
	STATE,
	RANGE
};

enum Action
{
	EXECUTE = true,
	STOP = false
};

enum State
{
	PRESSED = true,
	RELEASED = false
};

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(FSM* fsm) = 0;
	virtual InputType get_input_type() = 0;
};

class InputHandler
{
private:
	// Pointers to all commands
	Command* pressJump;
	Command* pressWalk;

	std::map <int, Command*> commands;

	// Gameplay context 
	std::map <int, State> state_map;
	std::map <int, Action> action_map;

	bool input_mapping();
	void dispatcher(std::vector<Command*>& command_queue);

	void keydown(SDL_Event& event);
	void keyup(SDL_Event& event);

	bool is_held(int key);
	bool was_pressed(int key);

public:
	InputHandler();
	~InputHandler();
	bool fill(std::vector<Command*>& command_queue);
};

class Jump : public Command
{
public:
	void execute(FSM* fsm) { fsm->jumping(); }
	InputType get_input_type() { return STATE; }
};

class Walk : public Command
{
public:
	void execute(FSM* fsm) { fsm->walking(); }
	InputType get_input_type() { return STATE; }
};