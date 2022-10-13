#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{

	bool write = true;

	int num_jokers = 0;
	int joker_indices[256];

	ifstream input_file("FindWord.txt");
	if (input_file.fail())
	{
		std::cout << "Couldn't open file\n";
		return 1;
	}

	// print the original file contents
	std::cout << "The original contents of the file are : \n\n";
	while (!input_file.eof())
		std::cout << (char) input_file.get();
	std::cout << "\n\n";

	input_file.clear();
	input_file.seekg(0, std::ios::beg);

	string to_find = "Joker";

	char c;
	while (!input_file.eof())
	{
		int char_index = (int)input_file.tellg();

		int i = 0;
		while (!isspace(c = input_file.get()))
		{
			if (c == to_find[i])
				i++;
			else
				break;
		}

		if (i == to_find.size() && isspace(c))
			joker_indices[num_jokers++] = char_index;

	}

	input_file.clear();
	input_file.seekg(0, std::ios::beg);

	string to_write;
	if (num_jokers >= 2)
	{

		int stop = joker_indices[1];
		int resume = joker_indices[1] + to_find.size();
		string replacement = "Alex";

		while (!input_file.eof())
		{
			if ((int) input_file.tellg() == stop)
			{
				to_write += replacement;
				input_file.seekg(resume, std::ios::beg);
			}

			to_write += input_file.get();

		}

	}

	input_file.close();
	if (write)
	{
		ofstream output_file("FindWord.txt");
		if (output_file.fail())
		{
			std::cout << "Couldn't open file for output.\n";
			return 1;
		}

		for (int i = 0; i < to_write.size(); i++)
		{
			output_file << to_write[i];
		}

		output_file.close();
	}

	std::cout << "The number of jokers is: " << num_jokers << "\n";

	std::cout << "There are jokers at ";
	for (int i = 0; i < num_jokers; i++)
	{
		std::cout << joker_indices[i] << ", ";
	}
	std::cout << "\n";

	// print the contents of the new file
	std::cout << "The contents of the new file are: \n\n" << to_write << "\n";

	return 0;
}