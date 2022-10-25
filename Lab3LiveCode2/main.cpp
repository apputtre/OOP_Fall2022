#include <iostream>
#include "my_func.h"
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::ifstream;

int main()
{
	string input;
	cout << "Enter the array of characters: ";
	cin >> input;
	std::cout << "# of R's: " << countr((char*)input.c_str(), input.length()) << "\n\n";

	string to_open = "arr.txt";

	ifstream input_file = ifstream(to_open);

	if (input_file.fail())
	{
		std::cout << "couldn't open file for input" << "\n";
		return 1;
	}

	char c;
	int num_rows = 0;
	int num_cols = 0;
	while (!input_file.eof())
	{
		c = input_file.get();

		if (c != '\t' && c != '\n')
		{
			if (num_rows == 0)
				num_cols++;
		}
		else if (c == '\n')
			num_rows++;
	}
	num_rows++;

	char* grid = (char*)malloc(num_rows * num_cols * sizeof(char));

	input_file.clear();
	input_file.seekg(0, std::ios::beg);

	int index = 0;
	while (!input_file.eof())
	{
		c = input_file.get();

		if (!isspace(c))
		{
			grid[index++] = c;
		}
	}

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
		{
			std::cout << grid[row * num_cols + col] << " ";
		}
		std::cout << "\n";
	}

	string to_find = "bot";

	std::cout << "\n# of bot's: " << countbot(grid, num_rows, num_cols, to_find) << "\n";

}