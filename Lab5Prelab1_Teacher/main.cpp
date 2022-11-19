#include <iostream>
#include <string>
#include "Human.h"
#include "Teacher.h"

using std::cin;
using std::cout;
using std::string;

int main()
{
	Teacher* t = new Teacher("Feynman", 100);

	cout << "Name: " << t->getName() << "\n\n";

	cout << "Initial knowledge: " << t->getKnowledge() << "\n";
	cout << "Initial balance: " << t->getAccountBalance() << "\n";
	cout << "Working...\n";
	t->work();
	cout << "Knowledge: " << t->getKnowledge() << "\n";
	cout << "Balance: " << t->getAccountBalance() << "\n";
	cout << "Learning...\n";
	t->learn();
	cout << "Knowledge: " << t->getKnowledge() << "\n";
	cout << "Balance: " << t->getAccountBalance() << "\n";
	cout << "Working...\n";
	t->work();
	cout << "Knowledge: " << t->getKnowledge() << "\n";
	cout << "Balance: " << t->getAccountBalance() << "\n";
	cout << "Learning...\n";
	t->learn();
	cout << "Knowledge: " << t->getKnowledge() << "\n";
	cout << "Balance: " << t->getAccountBalance() << "\n";

	return 0;
}