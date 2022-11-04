#include <iostream>
#include "Customer.h"
#include "Celebrity.h"
#include "Family.h"

using std::cout;
using std::cin;

int main()
{
	Customer c1("Tom");
	Celebrity c2("Chris", Customer::BURGER);
	Celebrity c3("Anna", Customer::PIZZA, Customer::HOTDOG);
	Customer c4("Brad");
	Celebrity c5("Jose", Customer::HOTDOG, Customer::BURGER);
	Family c6;

	Customer* customers[6] = { &c1, &c2, &c3, &c4, &c5, &c6 };

	int total_profit = 0;
	for (int i = 0; i < 6; i++)
	{
		int amount_received = (*customers[i]).buyFood(1, Customer::BURGER);
		cout << (*customers[i]).getName() + " spends " << amount_received << ".\n";
		total_profit += amount_received;
	}

	cout << "Total profit: " << total_profit << "\n";

	return 0;

}