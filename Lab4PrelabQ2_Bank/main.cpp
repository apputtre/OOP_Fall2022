#include <iostream>
#include "Account.h"

using std::cout;
using std::cin;

int main()
{
	Account* acc = new Account("savings", 1000);
	cout << "Initial balance is $" << acc->getBalance() << ".\n";
	cout << "Depositing $1000\n";
	acc->deposit(1000);
	cout << "New balance is $" << acc->getBalance() << ".\n";
	cout << "Withdrawing $300\n";
	acc->withdraw(300);
	cout << "New balance is $" << acc->getBalance() << "\n";
	delete(acc);

	return 0;
}