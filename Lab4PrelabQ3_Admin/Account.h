#pragma once

#include <string>
#include "BankAdmin.h"

using std::string;

class Account
{
private:
	string name;
	float balance;

public:

	Account();
	Account(string name);
	Account(string name, float balance);

	void deposit(float amount);
	void withdraw(float amount);
	float getBalance();
	string getName();

	friend class BankAdmin;
};
