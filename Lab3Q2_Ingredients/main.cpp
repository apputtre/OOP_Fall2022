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

	// these parameters need to be constant so we can declare arrays which use them as dimensions
	const int num_rows = 10;
	const int num_cols = 10;
	const int num_ingredients = 8;

	// the list of ingredients being searched for
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

	// it's easier to work with 1d arrays, so we'll read the grid in as such
	char grid[num_rows * num_cols] = {};

	ifstream input_file = ifstream("ingredient.txt");

	if (input_file.fail())
	{
		cout << "Couldn't open file for input" << endl;
		return 1;
	}
	
	int index = 0;
	// this loop reads the contents of the file into the array
	while (input_file >> grid[index++]) {}

	input_file.close();

	int user_input = -1;
	while (user_input != 0)
	{
		cout << "Please make your selection:\n";
		cout << "1) Print board game\n";
		cout << "2) Check brother ingredient\n";
		cout << "3) Find an ingredient\n";
		cout << "4) Count vowels\n";
		cout << "0) Exit\n";

		cin >> user_input;

		switch (user_input)
		{
		case 1:
			print_board(grid, num_rows, num_cols);
			break;
		case 2:
		{
			for (int i = 0; i < num_ingredients; i++)
			{
				search_word(grid, num_rows, num_cols, ingredient_list[i]);
				std::cout << "\n";
			}
			break;
		}
		case 3:
		{
			string to_search;
			std::cout << "Enter the ingredient: ";
			cin >> to_search;
			search_word(grid, num_rows, num_cols, to_search);
		}
		case 4:
			std::cout << "# of vowels in bottom 5 rows: " << count_vowels(grid, num_rows, num_cols);
			std::cout << "\n";
			break;
		}
	}

	std::cout << "Goodbye...";

	return 0;
}