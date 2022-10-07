#include <iostream>
#include<fstream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{

	ifstream input_file("seats.txt");

	if (input_file.fail())
	{
		std::cout << "Couldn't open file for input.\n";
		return 1;
	}

	char seats[24][6];

	char c;
	for (int row = 0; row < 24; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			input_file >> seats[row][col];
		}
	}

	std::cout << "Welcome to the airline seating chart.\n";

	bool exit = false;
	while (!exit)
	{
		std::cout << "Please select one of the following options:\n";
		std::cout << "1 - Check Status\n2 - Modify seat status\n3 - Show seats\n4 - exit\n";

		int user_input;
		cin >> user_input;

		switch (user_input) {
		case 1:
		{
			int num_seats_available, num_seats_window, num_seats_aisle, num_seats_reserved;
			num_seats_available = num_seats_window = num_seats_aisle = num_seats_reserved = 0;
			for (int row = 0; row < 24; row++)
			{
				for (int col = 0; col < 6; col++)
				{
					if (seats[row][col] == 'A')
					{
						num_seats_available++;

						if (col == 0 || col == 5)
							num_seats_window++;
						if (col == 2 || col == 3)
							num_seats_aisle++;
					}
					else
					{
						num_seats_reserved++;
					}
				}
			}

			std::cout << "Available seats: " << num_seats_available << "\n";
			std::cout << "Aisle seats (available): " << num_seats_aisle << "\n";
			std::cout << "Window seats (available): " << num_seats_window << "\n";
			std::cout << "Reserved seats: " << num_seats_reserved << "\n";

		}
			break;
		case 2:
		{
			int row_number, col_number;
			row_number = col_number = -1;
			char status = -1;

			while (row_number < 1 || row_number > 24)
			{
				std::cout << "Enter row number (1-24): ";
				cin >> row_number;
				if (row_number < 1 || row_number > 24)
					std::cout << "Please enter a row number between 1 and 24.\n";
			}

			while (col_number < 1 || col_number > 6)
			{
				std::cout << "Enter a column number: ";
				cin >> col_number;
				if (col_number < 1 || col_number > 6)
					std::cout << "Please enter a row number between 1 and 6.\n";
			}

			while (status != 'A' && status != 'R')
			{
				std::cout << "Status: ";
				cin >> status;
				if (status != 'A' && status != 'R')
					std::cout << "Please enter 'A' or 'R'.\n";
			}

			seats[row_number - 1][col_number - 1] = status;
		}
			break;
		case 3:
		{
			std::cout << "--------------------Seat Chart--------------------\n";
			for (int row = 0; row < 24; row++)
			{

				std::cout << row + 1 << "\t";

				for (int col = 0; col < 6; col++)
				{
					std::cout << seats[row][col] << " ";
				}

				std::cout << "\n";
			}
			std::cout << "--------------------------------------------------\n\n";
		}
			break;
		case 4:
		{
			exit = true;
			break;
		}
		default:
		{
			std::cout << "Unrecognized input.\n";
			return 1;
		}
		}
	}

	input_file.close();
	ofstream output_file("seats.txt");

	if (output_file.fail())
	{
		std::cout << "Couldn't open file for output.\n";
		return 1;
	}

	for (int row = 0; row < 24; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			output_file << seats[row][col] << "\t";
		}
		output_file << "\n";
	}

	output_file.close();

	return 0;
}