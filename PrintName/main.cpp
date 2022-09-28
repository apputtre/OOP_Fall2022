#include <string>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::ofstream;	// output - create & write to a file
using std::ifstream;	// input - read from the file

int main() {

	/*
	string user_name;

	cout << "Please enter your username: ";
	//cin >> user_name;	// if there is a space, the rest of the name will be ignored
	getline(cin, user_name);

	cout << "Your username is " << user_name << "\n";
	*/

	// store number from 10 to 100 in an array

	int curr_val = 10;

	int num[10];
	for (int i = 0; i < 10; i++)
	{
		num[i] = curr_val;
		curr_val += 10;
	}

	for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
		/*
		if (num[i] == 70)
		{
			break;	// exit from current loop
		}
		*/

		if (num[i] == 40)
		{
			continue;
		}

		cout << num[i] << ", ";
	}
	cout << "\n";
	cout << "----------------------\n";
	
	// file
	//ofstream myfile("test.txt");

	//myfile << "Hello world!\n";
	//myfile << "My name is Alex";
	//myfile << "Test overwrite";

	// close the file
	//myfile.close();

	// read from a file
	ifstream myfile("test.txt");
	string sentence;	// create a variable to store a sentence
	myfile >> sentence;

	// close
	myfile.close();

	cout << sentence << "\n";

	return 0;
}