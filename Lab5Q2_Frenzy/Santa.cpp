#include "Santa.h"

Santa::Santa()
{
	name = "Default";
}

Santa::Santa(string name)
{
	this->name = name;
}

string Santa::getName()
{
	return "St. " + name;
}

float Santa::buyFood(int num, FOOD_ITEM item, int* inventory[3])
{
	srand(time(NULL));
	
	for (int i = 0; i < 2; i++)
	{
		int gift = rand() % 3;
		(*inventory[gift])++;

		std::cout << getName() << " gifts a ";

		switch (gift)
		{
		case 0:
			std::cout << "burger.\n";
			break;
		case 1:
			std::cout << "pizza.\n";
			break;
		case 2:
			std::cout << "hotdog.\n";
			break;
		}
	}

	return num * prices[item];
}
