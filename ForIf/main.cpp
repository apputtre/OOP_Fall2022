// receive a number from the user
// find sum of next 10 even numbers
// if number ends with 0, add 1000

#include <iostream>

int main()
{

	int input = -1;
	
	// receive a number from the user
	std::cout << "Please enter a number: ";
	std::cin >> input;

	input += input % 2;

	int sum = 0;
	for (int i = 0; i < 20; i += 2)
	{
		if ((input + i) % 10 == 0)
		{
			std::cout << sum << " + " << 1000 << " = " << sum + input + 1000 << "\n";
			sum += 1000;
		}
		else
		{
			std::cout << sum << " + " << input + i << " = " << sum + input + i << "\n";
		}

		sum += input + i;
	}

	std::cout << "The sum is " << sum;

	return 0;
}