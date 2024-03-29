#include <iostream>
#include "my_code.h"

using std::cout;
using std::cin;

int main()
{

	int scores[255];
	int num_scores = 0;

	int input = 0;

	while (input != -1)
	{
		cout << "Please enter the next score: ";
		cin >> input;

		if(input != -1)
		{
			if (input < -1 || input > 100)
				cout << "Please enter a score between 0 and 100.\n";
			else
			{
				scores[num_scores++] = input;
				cout << "The maximum score is " << max_test(scores, num_scores) << ".\n";
				cout << "The minimum score is " << min_test(scores, num_scores) << ".\n";
				cout << "The average score is " << avg_test(scores, num_scores) << ".\n";
			}
		}
	}

	cout << "You entered ";
	for (int i = 0; i < num_scores; i++)
		cout << scores[i] << " ";

	return 0;
}