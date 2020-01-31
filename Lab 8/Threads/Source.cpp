#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Input.h"
#include "Render.h"
#include "Physics.h"

//atomic numbers prevent data race, where 2 threads access shared variable at the same time.
std::atomic_int ticketNumber;
std::atomic_int nextTicket;
std::atomic_int ticketTurn[10];
int numThreads;
std::mutex messageOutputMutex;

sf::Vector2f playerPosition;

Game game;
Input input;
Render render;
Physics physics;

void TicketFunction() 
{
	int i = numThreads++; 

	while (true)
	{
		//Take a ticket
		ticketTurn[i] = ticketNumber.fetch_add(1);

		//Slow down the program so that we can read the console.
		std::this_thread::sleep_for(std::chrono::seconds(2));

		while (ticketTurn[i] != nextTicket)
		{
			continue;
		}

		//critical section
		messageOutputMutex.lock();
		std::cout << "Player Position " << playerPosition.x << " , " << playerPosition.y << std::endl;
		messageOutputMutex.unlock();

		if (i == 0)
		{
			game.update(playerPosition);
		}

		if (i == 1)
		{
			input.update(playerPosition);
		}

		if (i == 2)
		{
			render.update(playerPosition);
		}

		if (i == 3)
		{
			physics.update(playerPosition);
		}


		//exit protocol
		nextTicket += 1;

		messageOutputMutex.lock();
		//std::cout << data.str() << std::endl;
		std::cout << "t" << i << "\tnext = " << nextTicket << std::endl;
		std::cout <<  "---------------------------------------------------------------------- "  << std::endl;
		messageOutputMutex.unlock();
	}
}


int main()
{
	numThreads = 0;
	ticketNumber = 1;
	nextTicket = 1;

	std::thread t1 = std::thread(TicketFunction);
	std::thread t2 = std::thread(TicketFunction);
	std::thread t3 = std::thread(TicketFunction);
	std::thread t4 = std::thread(TicketFunction);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}