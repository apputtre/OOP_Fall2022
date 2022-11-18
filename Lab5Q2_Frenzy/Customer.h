#pragma once

#include <string>
#include <time.h>
#include <iostream>

using std::string;

class Customer {

protected:

	string name;

public:

	enum FOOD_ITEM {
		BURGER,
		PIZZA,
		HOTDOG,
		NONE
	};

	// prices are different
	const float prices[4] = { 8, 5, 12, 0 };

	virtual string getName();
	virtual float buyFood(int num);
	virtual float buyFood(int num, FOOD_ITEM item, int* inventory[3]);

	Customer();
	Customer(string name);

};