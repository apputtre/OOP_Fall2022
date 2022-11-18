#pragma once

#include "Customer.h"
#include <string>

using std::string;

class Celebrity : public Customer {

	FOOD_ITEM fav_food, allergic_food;

public:

	string getName();
	float buyFood(int num);
	float buyFood(int num, Customer::FOOD_ITEM item, int* inventory[3]);

	Celebrity();
	Celebrity(string name);
	Celebrity(string name, FOOD_ITEM fav_food);
	Celebrity(string name, FOOD_ITEM fav_food, FOOD_ITEM allergic_food);

};