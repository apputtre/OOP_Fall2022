#include "Account.h"

Account::Account()
{
	name = "NA";
	balance = 500;
}

Account::Account(string name)
{
	this->name = name;
	balance = 500;
}

Account::Account(string name, float balance)
{
	this->name = name;
	this->balance = balance;
}

void Account::deposit(float amount)
{
	balance += amount;
}

void Account::withdraw(float amount)
{
	balance -= amount;
}

float Account::getBalance()
{
	return balance;
}

string Account::getName()
{
	return name;
}
