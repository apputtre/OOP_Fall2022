#include <iostream>

int main()
{
	int soil[4][4] =
	{
		{15, 10, 8},
		{5, 13, 3},
		{41, 11, 11},
		{10, 5, 4}
	};

	int greatest = INT_MIN;
	int row_greatest = 0;
	int col_greatest = 0;

	const int num_rows = 4;
	const int num_cols = 3;

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
		{
			std::cout << soil[row][col] << "\t";
		}
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
		{
			if (soil[row][col] > greatest)
			{
				greatest = soil[row][col];
				row_greatest = row;
				col_greatest = col;
			}
		}
	}

	std::cout << "The greatest value is " << greatest << ", located at soil[" << row_greatest << "][" << col_greatest << "].\n";

	float averages[num_rows] = {};

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_cols; col++)
		{
			averages[row] += ((float)soil[row][col]) / num_cols;
		}
	}

	std::cout << "\n";

	for (int row = 0; row < num_rows; row++)
	{
		std::cout << "Average quality of row " << row << ": " << averages[row] << "\n";
	}

	return 0;
}