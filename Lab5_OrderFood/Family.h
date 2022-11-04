#pragma once

#include "Customer.h"

#include <string>
#include <time.h>
using std::string;

class Family : public Customer
{

public:

	string getName();
	float buyFood(int num);
	float buyFood(int num, FOOD_ITEM item);

	Family();
	Family(string name);
};