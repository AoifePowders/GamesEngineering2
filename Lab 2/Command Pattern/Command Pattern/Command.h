#include <iostream>
#include <list>
#include "SFML/Graphics.hpp"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;

protected:
	Command() {}
};

class Q : public Command
{
public:
	virtual void execute() { std::cout << "Q" << std::endl; }
};

class W : public Command
{
public:
	virtual void execute() { std::cout << "W" << std::endl; }
};

class E : public Command
{
public:
	virtual void execute() { std::cout << "E" << std::endl; }
};

class R : public Command
{
public:
	virtual void execute() { std::cout << "R" << std::endl; }
};

class T : public Command
{
public:
	virtual void execute() { std::cout << "T" << std::endl; }
};

class Y : public Command
{
public:
	virtual void execute() { std::cout << "Y" << std::endl; }
};

class TAB : public Command
{
public:
	virtual void execute() { std::cout << "REDO" << std::endl; }
};

class BACKSPACE : public Command
{
public:
	virtual void execute() { std::cout << "UNDO" << std::endl; }
};



class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();

private:
	std::list<Command*>* commands;
};