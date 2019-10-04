#include <map>
#include <vector>
#include <SDL.h>
#include "character.h"

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
	virtual void execute(Character* character) = 0;
	virtual InputType get_input_type() = 0;
};

class InputHandler
{
private:
	// Pointers to all commands
	Command* pressQ;
	Command* pressW;
	Command* pressE;
	Command* pressR;

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
	void configure(int key, Command* command);
};

class Q : public Command
{
public:
	void execute(Character* character) { character->pressQ(); }
	InputType get_input_type() { return STATE; }
};

class W : public Command
{
public:
	void execute(Character* character) { character->pressW(); }
	InputType get_input_type() { return STATE; }
};

class E : public Command
{
public:
	void execute(Character* character) { character->pressE(); }
	InputType get_input_type() { return STATE; }
};

class R : public Command
{
public:
	void execute(Character* character) { character->pressR(); }
	InputType get_input_type() { return STATE; }
};
