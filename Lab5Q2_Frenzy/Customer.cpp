#include "Customer.h"

Customer::Customer()
{
	name = "Sara";
}

Customer::Customer(string name)
{
	this->name = name;
}

string Customer::getName()
{
	return name;
}

float Customer::buyFood(int num)
{
	srand(time(NULL));

	float total_spent = 0;

	for (int i = 0; i < num; i++)
	{
		int selection = rand() % 4;
		int price = prices[selection];
		total_spent += price;

	}

	return total_spent;

}

float Customer::buyFood(int num, FOOD_ITEM item, int* inventory[3])
{
	return prices[item] * num;
}