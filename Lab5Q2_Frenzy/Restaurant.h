#pragma once

#include <string>
#include <iostream>
#include "Customer.h"

using std::string;
using std::cin;
using std::cout;

class Restaurant
{
	string name;
	int cash, num_burger, num_hotdog, num_pizza;

	static constexpr int prices[3] = { 5, 3, 7 };

	static enum FOOD_ITEMS {
		BURGER,
		PIZZA,
		HOTDOG
	};

public:
	Restaurant(string name);
	Restaurant(string name, int cash, int num_burger, int num_hotdog, int num_pizza);

	string getName();
	int orderFood();
	void checkInventory();
	void sellFood(Customer& c);
	int getCash();
};
