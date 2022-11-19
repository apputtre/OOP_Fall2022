#pragma once

#include <string>
#include "BankAccount.h"

using std::string;

class Human
{
protected:
	string name;
	BankAccount bank;

public:
	Human();
	Human(string name, float init_amount);
	virtual string getName();
	void setName(string name);
	void receiveMoney(float amount);
	void spendMoney(float amount);
	float getAccountBalance();
};
