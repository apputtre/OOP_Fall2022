#include <iostream>
#include <fstream>
#include "my_funcs.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

int main()
{

	const int num_rows = 10;
	const int num_cols = 10;
	const int num_ingredients = 8;

	string ingredient_list[] = {
		"GARLIC",
		"SPINACH",
		"TOMATO",
		"BREAD",
		"SUGAR",
		"PASTA",
		"ORANGE",
		"MILK"
	};

	char grid[num_rows * num_cols] = {};

	ifstream input_file = ifstream("ingredient.txt");

	if (input_file.fail())
	{
		cout << "Couldn't open file for input" << endl;
		return 1;
	}
	
	// load the file into an array
	int index = 0;
	while (input_file >> grid[index++]) {}

	input_file.close();

	int user_input = -1;
	while (user_input != 0)
	{
		cout << "Please make your selection:\n";
		cout << "1) Print board game\n";
		cout << "2) Check brother ingredient\n";
		cout << "3) Find an ingredient\n";
		cout << "0) Exit\n";

		cin >> user_input;

		switch (user_input)
		{
		case 1:
			print_board(grid, num_rows, num_cols);
			break;
		case 2:
		{
			string to_search;
			std::cout << "Enter the ingredient: ";
			cin >> to_search;
			search_word(grid, num_rows, num_cols, to_search);
			break;
		}
		case 3:
			break;
		}
	}

	return 0;
}