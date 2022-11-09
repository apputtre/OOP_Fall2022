#include "BankAdmin.h"

BankAdmin::BankAdmin() {}

void BankAdmin::setName(Account* acc, string name)
{
	acc->name = name;
}

float BankAdmin::interest(Account* acc, float amount)
{
	acc->balance += amount;
	return acc->getBalance();
}

float BankAdmin::changeBalance(Account* acc, float balance)
{
	acc->balance = balance;
	return acc->getBalance();
}
