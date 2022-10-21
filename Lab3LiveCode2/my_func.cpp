#include "my_func.h"

int countr(char arr[], int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == 'R')
			count++;
	}
	return count;
}

int countbot(char grid[], int num_rows, int num_cols, string to_find)
{
	// we're going to modify the array, so we'll make a copy
	char* temp_grid = (char*) malloc(num_rows * num_cols * sizeof(char));
	memcpy(temp_grid, grid, num_rows * num_cols * sizeof(char));

	bool found_char, exit = false;
	int count = 0;

	int index = 0;
	while(!exit)
	{
		found_char = false;

		for (int row = 0; row < num_rows; row++)
		{
			for (int col = 0; col < num_cols; col++)
			{
				if (num_rows - row <= 5)
				{
					if (temp_grid[row * num_cols + col] == to_find[index])
					{
						found_char = true;

						if (index == to_find.length() - 1)
							count++;

						index = (index + 1) % to_find.length();

						temp_grid[row * num_cols + col] = ' ';
					}
				}
			}
		}

		if (!found_char)
			exit = true;
	}

	return count;
}