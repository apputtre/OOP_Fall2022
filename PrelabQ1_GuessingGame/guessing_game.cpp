/*
Alexander Puttre
ELEC3150
Lab 2
9/23/2022
*/

#include<iostream>
#include<cstdlib>

int main()
{
	srand(time(0));

	int answer = rand() % 100 + 1;

	std::cout << "The answer is " << answer << ".\n\n";
	
	int guess = -1;
	while (guess != answer)
	{
		std::cout << "Please enter a guess between 1 and 100: ";
		std::cin >> guess;

		if (guess > answer)
			std::cout << "Your guess is too large.\n";
		else if (guess < answer)
			std::cout << "Your guess is too small.\n";
	}

	std::cout << "Your guess is correct! The answer was " << answer << ".\n";

	return 0;
}
