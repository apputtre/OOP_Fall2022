#include "my_funcs.h"

void print_board(char grid[], int num_rows, int num_cols)
{
	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			std::cout << grid[r * num_cols + c] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void search_word(char grid[], int num_rows, int num_cols, string word)
{
	std::cout << "Search: " << word << "\n";
	std::cout << "word_len" << word.length() << "\n";

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			int char_count = 0;

			// check left
			// char_count is the number of found characters in a word
			char_count = 0;

			for (int j = 0; j < word.length(); j++)
			{
				if (c - j > 0)
				{
					if (grid[r * num_cols + (c - j)] == word[j])
					{
						char_count++;
					}
				}
			}
			if (char_count == word.length())
			{
				// we found the word!
				std::cout << "found at (" << r << ", " << c << ") from right to left.\n";
				return;
			}

			// check right
			// char_count is the number of found characters in a word
			char_count = 0;

			for (int j = 0; j < curr_word.length(); j++)
			{
				if (c + j < num_cols)
				{
					if (grid[r * num_cols + (c + j)] == curr_word[j])
					{
						char_count++;
					}
				}
			}
			if (char_count == curr_word.length())
			{
				// we found the word!
				std::cout << " found at (" << r << ", " << c << ") from left to right.\n";
				return;
			}

			// check up
			curr_word = word;
			// char_count is the number of found characters in a word
			int char_count = 0;

			for (int j = 0; j < curr_word.length(); j++)
			{
				if (r - j > 0)
				{
					if (grid[(r - j) * num_cols + c] == curr_word[j])
					{
						char_count++;
					}
				}
			}
			if (char_count == curr_word.length())
			{
				// we found the word!
				std::cout << " found at (" << r << ", " << c << ") from down to up.\n";
				return;
			}

			// check down
			curr_word = word;
			// char_count is the number of found characters in a word
			int char_count = 0;

			for (int j = 0; j < curr_word.length(); j++)
			{
				if (r + j < num_rows)
				{
					if (grid[(r + j) * num_cols + c] == curr_word[j])
					{
						char_count++;
					}
				}
			}
			if (char_count == curr_word.length())
			{
				// we found the word!
				std::cout << " found at (" << r << ", " << c << ") from up to down.\n";
				return;
			}
		}
	}

	std::cout << "not found\n";
}