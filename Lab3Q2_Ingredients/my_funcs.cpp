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

	// since it's easier to pass 1d arrays to functions, this function operates on a linear array

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

			// if the index variable equals the length of the word, then every letter in the word was found
			if (char_index == word.length())
			{
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

			// if the index variable equals the length of the word, then every letter in the word was found
			if (char_index == word.length())
			{
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

			// if the index variable equals the length of the word, then every letter in the word was found
			if (char_index == word.length())
			{
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

			// if the index variable equals the length of the word, then every letter in the word was found
			if (char_index == word.length())
			{
				std::cout << "found at (" << row << ", " << col << ") from up to down.\n";
				return;
			}
		}
	}

	// if the function didn't exit in the loops above, then the word wasn't found
	std::cout << "not found\n";
}

int count_vowels(char grid[], int num_rows, int num_cols)
{

	string vowels = "AEIOU";
	int num_vowels = 0;

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
		{
			if (num_rows - row <= 5)
				for (char c : vowels)
					if (c == toupper(grid[row * num_cols + col]))
						num_vowels++;
		}
	}

	return num_vowels;
}