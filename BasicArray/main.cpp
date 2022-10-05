#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
	// create an array to store 5 tests
	int test[5] = { 10, 20, 30 };

	cout << "Your score is ";
	for (int i = 0; i < 5; std::cout << test[i++] << " ");
	cout << "\n";

	// update a score of test 2
	test[2] = 32;

	// check how many elements are in the array
	cout << "size of test: " << sizeof(test) / sizeof(test[0]) << "\n";

	float avg = 0.0;
	for (int i = 0; i < 5; avg += test[i++] / 5.0);

	cout << "The average score is " << avg;

	// string
	string name = "Alex";
	cout << "My name is " << name << "\n";
	cout << "The first letter of my name is " << name[0] << "\n";
	name[0] = 'Z';
	cout << "Now the fist letter of my name is " << name[0];

	return 0;
}