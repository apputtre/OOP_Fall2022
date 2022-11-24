#include "BankAccount.h"
#include <iostream>

using std::cin;
using std::cout;

BankAccount::BankAccount()
{
	cash = 0;
}

BankAccount::BankAccount(float amount)
{
	cash = amount;
}

float BankAccount::getBalance()
{
	return cash;
}

void BankAccount::deposit(float amount)
{
	cash += amount;
}

void BankAccount::withdraw(float amount)
{
	if (cash - amount > 0)
		cash -= amount;
}