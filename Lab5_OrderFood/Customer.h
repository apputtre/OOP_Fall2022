#pragma once

#include <string>
#include <time.h>

using std::string;

class Customer {

protected:

	string name;

public:

	enum FOOD_ITEM {
		NONE,
		BURGER,
		PIZZA,
		HOTDOG
	};

	float prices[4] = {5, 8, 12, 0};

	virtual string getName();
	virtual float buyFood(int num);
	virtual float buyFood(int num, FOOD_ITEM item);

	Customer();
	Customer(string name);

};