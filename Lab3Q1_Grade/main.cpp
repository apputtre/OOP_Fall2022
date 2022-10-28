#include <iostream>
#include "gradeutils.h"

using std::cout;
using std::cin;

int main()
{
	// initialize the test scores
	int grades[] = {8, 10, 8, 5, 7, 8, 9, 10, 6, 7};
	// calculate the size of the array (should always be 10)
	int num_grades = sizeof(grades) / sizeof(grades[0]);

	bool exit = false;
	// enter the main loop
	while (!exit)
	{
		cout << "\n";
		cout << "1. Modify\n";
		cout << "2. Grade\n";
		cout << "3. Avg\n";
		cout << "4. Show\n";
		cout << "5. Sum >= 6\n";
		cout << "6. Exit\n";
		cout << "\n";

		// make sure user input is within expected bounds
		int input = -1;
		while (input == -1)
		{

			std::cout << "Please enter your selection: ";

			cin >> input;
			if (input < 1 || input > 6)
			{
				std::cout << "Please enter a number between 1 and 6.\n";
				input = -1;

			}
		}

		std::cout << "\n";

		switch (input)
		{
		case 1:
			int test_num, new_score;

			std::cout << "Please enter which test you would like to modify: ";
			cin >> test_num;
			std::cout << "Please enter the new score: ";
			cin >> new_score;
			modify(grades, test_num - 1, new_score);
			std::cout << "Test " << test_num << " is now " << new_score << ".\n";
			break;
		case 2:
			std::cout << "The sum of the grades is " << sum_arr(grades, num_grades) << ".\n";
			std::cout << "Grade: " << grade(grades, num_grades) << "\n";
			break;
		case 3:
			std::cout << "This student's average is " << avg(grades, num_grades) << ".\n";
			break;
		case 4:
			show(grades, num_grades);
			std::cout << "\n";
			break;
		case 5:
			cout << "The sum of scores >= 6 is " << sum_gteq6(grades, num_grades) << ".\n";
			break;
		case 6:
			exit = true;
			break;
		}

	}

	std::cout << "Goodbye...\n";

	return 0;
}