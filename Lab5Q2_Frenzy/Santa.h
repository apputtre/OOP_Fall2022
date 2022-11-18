#pragma once

#include "Customer.h"
#include "time.h"

class Santa : public Customer
{

public:
	string getName();
	float buyFood(int num, FOOD_ITEM item, int* inventory[3]);

	Santa();
	Santa(string name);

};
