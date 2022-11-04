#include "Family.h"

#include <string>
using std::string;

Family::Family() : Customer() {}

Family::Family(string name) : Customer(name) {}

string Family::getName()
{
	return name + ", my family";
}

float Family::buyFood(int num) { return -1; }

float Family::buyFood(int num, FOOD_ITEM item)
{
	int total_spent = 0;

	srand(time(NULL));

	for (int i = 0; i < num; i++)
	{
		int amount = 20 + (rand() % 31);
		total_spent += amount;
	}

	return total_spent;

}