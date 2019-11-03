#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"

using namespace std;

int main()
{
	Production p;
	//fail
	assert(p.someMethod() == 0);
	std::cout << "ASSERTION FAILED" << std::endl;
	//pass
	assert((p.someMethod() == 1));
	std::cout << "ASSERTION PASSED" << std::endl;
	cin.get();

	system("PAUSE");
}