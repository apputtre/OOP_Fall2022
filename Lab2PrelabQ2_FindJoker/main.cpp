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

	int num_jokers = 0;
	int joker_indices[255];

	ifstream input_file;
	ofstream output_file;
	input_file.open("FindWord.txt");

	if (input_file.fail())
	{
		std::cout << "couldn't open file\n";
		return 1;
	}

	string curr_word, temp_str;

	int index = 0;
	while (input_file >> curr_word)
	{
		if (curr_word == "Joker")
			joker_indices[num_jokers++] = index;
		
		if (num_jokers == 2)
		{
			temp_str.append("Alex");
		}

		temp_str.append(curr_word);

		index++;
	}

	std::cout << "Number of jokers: " << num_jokers << "\n";

	input_file.close();

	return 0;
}