#include <iostream>
#include <string>

const std::string names[] = {
	std::string("David"),
	std::string("Jose"),
	std::string("Mike"),
	std::string("Alishia"),
	std::string("Kate"),
	std::string("Dan"),
	std::string("Ellen"),
	std::string("Nate")
};

int main()
{

	std::string input;

	bool found_username = false;
	while (!found_username)
	{
		std::cout << "Please enter your username: ";

		std::cin >> input;

		for (int i = 0; i < sizeof(names); i++)
		{
			if (input == names[i]) {
				found_username = true;
				break;
			}
		}

		if (!found_username)
		{
			std::cout << "That username is not in the system.\n";
		}
	}

	std::cout << "Your username is in the system.";

}