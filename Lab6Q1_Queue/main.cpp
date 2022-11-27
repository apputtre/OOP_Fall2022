#include <iostream>
#include "Customer.h"
#include <vector>
#include <time.h>
#include <cstdlib>

using std::cout;
using std::cin;
using std::vector;

std::ostream& operator<<(std::ostream& os, vector<Customer>& vec);

int main()
{
	srand(time(NULL));

	const int num_names = 8;
	string names[num_names] = { "Bob", "Tim", "Sue", "Jim", "Hans", "Fred", "Sally", "Alex" };

	vector<Customer> queue;
	// populate the queue with customers
	for (int i = 0; i < 5; i++)
		queue.push_back(Customer(names[rand() % num_names]));

	int sum = 0;
	bool exit = false;
	while (!exit)
	{
		cout << "----- Customers in Line -----\n";
		// create a new customer to add to the queue
		cout << "Enter a name for the new customer: ";
		string name;
		cin >> name;
		queue.push_back(Customer(name));

		cout << queue[queue.size() - 1].getName() << " has joined the queue.\n";

		// serve customers
		for(int i = 0; i < 2; i++)
			if (queue.size() > 0)
			{
				Customer customer_served = queue[0];
				queue.erase(queue.begin());

				cout << "-----REGISTER " << i + 1 << "----- \n";
				int amount_spent = customer_served.spendMoney();
				cout << customer_served.getName() << " spent " << amount_spent << ".\n";
				sum += amount_spent;
			}

		cout << "\n";

		exit = queue.size() == 0;
	}

	cout << "All customers have been served.\n";
	cout << "Total amount spent: $" << sum << "\n";

	return 0;
}

std::ostream& operator<<(std::ostream& os, vector<Customer>& vec)
{
	for (vector<Customer>::iterator it = vec.begin(); it < vec.end(); it++)
		os << std::distance(vec.begin(), it) << ": " << (*it).getName() << ", ";

	return os;
}