#pragma once

class BankAccount
{
	float cash;

public:
	BankAccount();
	BankAccount(float amount);

	float getBalance();
	void deposit(float amount);
	void withdraw(float amount);
	void interest(float percent);
};
