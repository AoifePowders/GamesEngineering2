#include "InputHandler.h"

InputHandler::InputHandler()
{

	// Create pointers to all commands 
	pressJump = new Jump();
	pressWalk = new Walk();

	commands[SDLK_q] = pressJump;
	commands[SDLK_w] = pressWalk;

}

//fills the queue with buttons that have been presed
bool InputHandler::fill(std::vector<Command*>& command_queue)
{
	bool exit = input_mapping();    // converts raw input data to an action and/or state

	if (exit) return true;
	else {
		dispatcher(command_queue);  // fills command queue
		action_map.clear();         // clears key presses
		return false;
	}
}

//detects input and cretaes an SDL event
//returns true if key down return true and triggers an event
bool InputHandler::input_mapping()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
		if (event.type == SDL_QUIT) return true;
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) return true;
			keydown(event);
		}
		else if (event.type == SDL_KEYUP)
			keyup(event);

	return false;
}

//calls input mapping.
//converts to bool/state and returns true if button pressed.
//if false returns false and clears all acions
void InputHandler::dispatcher(std::vector<Command*>& command_queue)
{
	std::map<int, Command*>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++) {
		if (is_held(iter->first) && iter->second->get_input_type() == STATE)
			command_queue.push_back(iter->second);
		else if (was_pressed(iter->first) && iter->second->get_input_type() == ACTION)
			command_queue.push_back(iter->second);
	}
}

void InputHandler::keydown(SDL_Event& event)
{
	if (state_map[event.key.keysym.sym] == RELEASED)
		action_map[event.key.keysym.sym] = EXECUTE;
	state_map[event.key.keysym.sym] = PRESSED;
}

void InputHandler::keyup(SDL_Event& event)
{
	state_map[event.key.keysym.sym] = RELEASED;
}

bool InputHandler::is_held(int key)
{
	return state_map[key];
}

bool InputHandler::was_pressed(int key)
{
	return action_map[key];
}

InputHandler::~InputHandler()
{
	// Delete all command pointers    
	std::map<int, Command*>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++)
		delete iter->second;
}