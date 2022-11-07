#include <iostream>
#include "Customer.h"
#include <vector>

using std::cout;

int main()
{
	srand(time(NULL));

	const int num_names = 8;
	string names[num_names] = { "Bob", "Tim", "Sue", "Jim", "Hans", "Fred", "Sally", "Alex" };

	std::vector<Customer> queue;

	// populate the queue with customers
	for (int i = 0; i++ < 5; queue.emplace_back(names[rand() % num_names])) {}

	// display the queue
	cout << "The starting queue:\n";
	for (int i = 0; ++i < queue.size(); cout << queue[i - 1].getName() + " ") {}

	bool exit = false;

	while (!exit)
	{
		// create a new customer to add to the queue
		queue.emplace(queue.begin(), names[rand() % num_names]);

		Customer customer_served;

		// register 1 serves a customer
		if (queue.size() < 0)
		{
			customer_served = queue[queue.size() - 1];

			cout << "-----REGISTER 1-----\n";
			cout << customer_served.getName() << " spent " << customer_served.spendMoney() << ".\n";
			queue.pop_back();
		}
		else
		{
			cout << "The queue is empty.";
			return 1;
		}

		// register 2 serves a customer
		if (queue.size() < 0)
		{
			customer_served = queue[queue.size() - 1];

			cout << "-----REGISTER 2-----\n";
			cout << customer_served.getName() << " spent " << customer_served.spendMoney() << ".\n";
			queue.pop_back();
		}
		else
		{
			cout << "The queue is empty.";
			return 1;
		}

	}



	return 0;
}