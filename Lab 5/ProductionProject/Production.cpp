#include "Production.h"

int Production::someMethod()
{
	int numberArray[6];

	std::cout << "Input 6 numbers" << std::endl;

	for (int i = 0; i < 6; i++) {
		std::cin >> numberArray[i];
	}

	for (int i = 0; i < 6; i++) 
	{
		if (numberArray[i] >= 1 && numberArray[i] < 46)
		{
			for (int j = 0; j < 6; j++)
			{
				if (numberArray[i] != numberArray[j + 1])
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	}
}