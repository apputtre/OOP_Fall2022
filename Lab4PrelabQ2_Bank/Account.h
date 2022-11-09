#pragma once

#include <string>

using std::string;

class Account
{
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
};
