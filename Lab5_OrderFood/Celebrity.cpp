#include "Celebrity.h"
#include <string>

using std::string;

string Celebrity::getName()
{
	return "Lady/Gentleman " + name;
}

float Celebrity::buyFood(int num)
{
	srand(time(NULL));

	float total_spent = 0;

	for (int i = 0; i < num; i++)
	{
		int selection = rand() % 4;
		int tip = 0;

		if (selection == fav_food)
		{
			tip = 5;
		}
		else if (selection != allergic_food)
		{
			tip = 2;
		}

		int price = prices[selection];
		total_spent += price + tip;

	}

	return total_spent;
}

float Celebrity::buyFood(int num, Customer::FOOD_ITEM item)
{
	int total_spent = 0;

	for (int i = 0; i < num; i++)
	{
		int selection = item;
		int tip = 0;

		if (selection == fav_food)
		{
			tip = 5;
		}
		else if (selection != allergic_food)
		{
			tip = 2;
		}

		total_spent += prices[selection] + tip;

	}

	return total_spent;
}

Celebrity::Celebrity() : Customer()
{
	fav_food = BURGER;
	allergic_food = PIZZA;
}

Celebrity::Celebrity(string name) : Customer(name)
{
	fav_food = BURGER;
	allergic_food = PIZZA;
}

Celebrity::Celebrity(string name, FOOD_ITEM fav_food) : Customer(name)
{
	this->fav_food = fav_food;
	allergic_food = PIZZA;
}

Celebrity::Celebrity(string name, FOOD_ITEM fav_food, FOOD_ITEM allergic_food) : Customer(name)
{
	this->fav_food = fav_food;
	this->allergic_food = allergic_food;
}