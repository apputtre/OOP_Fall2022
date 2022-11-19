#include "Human.h"

Human::Human()
{
	name = "None";
	bank = BankAccount(0);
}

Human::Human(string name, float init_amount)
{
	name = name;
	bank = BankAccount(init_amount);
}

string Human::getName()
{
	return name;
}

void Human::setName(string name)
{
	this->name = name;
}

void Human::receiveMoney(float amount)
{
	bank.deposit(amount);
}

float Human::getAccountBalance()
{
	return bank.getBalance();
}