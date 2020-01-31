#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
#include <mutex>

std::mutex mutex_;
std::condition_variable condition_variable;
std::queue<int> queue;
bool ready = false;
int NO_BURGERS = 20;

void produce()
{
	for (int i = 0; i <=  NO_BURGERS; i++)
	{
		std::cout << "Burger "<< i << " ready"<< std::endl;
		//push each burger to queue
		queue.push(i);
		//when info is ready to be output
		ready = true;
		//notify all threads the burger is ready
		condition_variable.notify_all();
		//wait for 2 seconds
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}


void consume()
{
	//waits for burger to be ready
	std::unique_lock<std::mutex> clock(mutex_);
	condition_variable.wait(clock, [] {return ready; });
	while (true)
	{
		while (!queue.empty())
		{
			//eat the burger
			std::cout << "Eat Burger" << std::endl;
			//remove it from the queue
			queue.pop();
			ready = false;
		}
	}
}

int main()
{
	std::thread first(produce);
	std::thread second(consume);

	first.join();
	second.join();
}
