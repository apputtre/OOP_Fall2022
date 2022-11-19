#include <iostream>
#include "BankAdmin.h"
#include "Account.h"

using std::cin;
using std::cout;

int main()
{

	Account* acc = new Account();
	BankAdmin admin;

	cout << "Account name: " << acc->getName() << ".\n";
	cout << "Account balance: " << acc->getBalance() << ".\n";
	cout << "Changing account name to \'Peter\'\n";
	admin.setName(*acc, "Peter");
	cout << "Account name: " << acc->getName() << ".\n";
	cout << "Adding $10 of interest.\n";
	admin.interest(*acc, 10);
	cout << "Balance: " << acc->getBalance() << ".\n";
	cout << "Changing total balance to $50.\n";
	admin.changeBalance(*acc, 50);
	cout << "Balance: " << acc->getBalance() << "\n";
	
	return 0;
}