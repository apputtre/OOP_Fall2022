#include <iostream>
#include "find_tax.h"

using std::cout;
using std::cin;

int main()
{

	float price, rate, quantity;

	price = 10;
	rate = 0.1;
	quantity = 1;

	cout << "\nTotal cost: " << find_tax(price, rate, quantity);

	return 0;
}