#include "Restaurant.h"
#include "Customer.h"
#include "Celebrity.h"
#include "Santa.h"

int main()
{

	Customer c1("Tom");
	Celebrity c2("Chris", Customer::BURGER);
	Celebrity c3("Anna", Customer::PIZZA, Customer::HOTDOG);
	Santa c4("Jerry");
	Customer c5("Brad");
	Santa c6("Rob");
	Celebrity c7("Jose", Customer::HOTDOG, Customer::BURGER);

	Customer* customers[7] = { &c1, &c2, &c3, &c4, &c5, &c6, &c7 };

	Restaurant r("My Restaurant");

	for (int day = 0; day < 3; day++)
	{
		while (r.orderFood()) {};

		cout << "---------- Day " << (day + 1) << " ----------\n";

		for (Customer* c : customers)
			r.sellFood(*c);
		
		cout << "---------- End of day " << (day + 1) << " ----------\n";

		if (r.getCash() < 0)
		{
			cout << "You're bankrupt!\n";
			return 0;
		}
	}

	return 0;
}