#pragma once

#include "Account.h"

class BankAdmin
{
public:

	void setName(Account* acc, string name);
	float interest(Account* acc, float amount);
	float changeBalance(Account* acc, float balance);

	BankAdmin();	
};
