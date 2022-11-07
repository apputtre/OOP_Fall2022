#pragma once

#include <string>
#include <time.h>

using std::string;

class Customer {

	string name;
	int money;

public:

	Customer(string name, int money);
	Customer(string name);
	Customer();

	string getName();
	void setName(string name);
	int getMoney();
	void setMoney(int val);
	int spendMoney();

};