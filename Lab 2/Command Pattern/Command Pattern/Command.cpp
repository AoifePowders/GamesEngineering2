#include "Command.h"

MacroCommand::MacroCommand()
{
}

MacroCommand::~MacroCommand()
{
}

void MacroCommand::add(Command* c)
{
	commands->push_back(c);
}

void MacroCommand::remove(Command* c)
{
	commands->push_back(c);
}

void MacroCommand::execute()
{
	std::list<Command*>list;
	for (auto i = list.cbegin(); i != list.cend(); i++)
	{
		Command* c = *i;
		c->execute();
	}
}
