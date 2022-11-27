#include "Customer.h"

Customer::Customer(string name, int money)
{
	this->name = name;
	this->money = money;
}

Customer::Customer(string name)
{
	this->name = name;

	money = (float) (10 + rand() % 21);

}

Customer::Customer()
{
	name = "Default";

	srand(time(NULL));

	money = (float)(10 + rand() % 21);
}

string Customer::getName()
{
	return name;
}

void Customer::setName(string name)
{
	this->name = name;
}

int Customer::getMoney()
{
	return money;
}

void Customer::setMoney(int val)
{
	this->money = val;
}

int Customer::spendMoney()
{
	int money_spent = 1 + rand() % money;

	money -= money_spent;

	return money_spent;
}