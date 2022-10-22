#include "my_funcs.h"

void print_board(char grid[], int num_rows, int num_cols)
{
	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
		{
			std::cout << grid[row * num_cols + col] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void search_word(char grid[], int num_rows, int num_cols, string word)
{
	std::cout << "Search: " << word << "\n";
	std::cout << "word_len" << word.length() << "\n";

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
		{
			// check left
			int char_index = 0;
			while (col - char_index > 0)
			{
				if (toupper(grid[row * num_cols + col - char_index]) != toupper(word[char_index]))
					break;
				char_index++;
			}

			if (char_index == word.length())
			{
				// we found the word!
				std::cout << "found at (" << row << ", " << col << ") from right to left.\n";
				return;
			}

			// check right
			char_index = 0;
			while (col + char_index < num_cols)
			{
				if (toupper(grid[row * num_cols + col + char_index]) != toupper(word[char_index]))
					break;
				char_index++;
			}

			if (char_index == word.length())
			{
				// we found the word!
				std::cout << "found at (" << row << ", " << col << ") from left to right.\n";
				return;
			}

			// check up
			char_index = 0;
			while (row - char_index > 0)
			{
				if (toupper(grid[(row - char_index) * num_cols + col]) != toupper(word[char_index]))
					break;
				char_index++;
			}

			if (char_index == word.length())
			{
				// we found the word!
				std::cout << "found at (" << row << ", " << col << ") from down to up.\n";
				return;
			}
			// check down
			char_index = 0;
			while (col + char_index < num_rows)
			{
				if (toupper(grid[(row + char_index) * num_cols + col]) != toupper(word[char_index]))
					break;
				char_index++;
			}

			if (char_index == word.length())
			{
				// we found the word!
				std::cout << "found at (" << row << ", " << col << ") from up to down.\n";
				return;
			}
		}
	}

	std::cout << "not found\n";
}