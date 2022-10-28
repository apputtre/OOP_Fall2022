#include <iostream>
#include <string>
#include <time.h>

#include "Fighter.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
	string str_input;
	int num_input;

	cout << "Welcome to the boxing game!\n";
	cout << "Please enter your name: ";
	cin >> str_input;
	cout << str_input << ", prepare to enter a world of pain\n\n";

	int level = 0;
	Fighter player1(str_input, 100, 100);
	
	while(level < 3)
	{
		Fighter player2;

		switch (level)
		{
		case 0:
		{
			cout << "LEVEL 1\n";
			player2.set_name("Ryan");
			player2.set_power(70);
			player2.set_max_power(70);
			player2.set_health(70);
			break;
		}
		case 1:
		{
			cout << "LEVEL 2\n";
			player2.set_name("Pete");
			player2.set_power(100);
			player2.set_max_power(100);
			player2.set_health(100);
			break;
		}
		case 2:
		{
			cout << "LEVEL 3\n";
			player2.set_name("Boss");
			player2.set_power(150);
			player2.set_max_power(150);
			player2.set_health(150);
			break;
		}
		}

		cout << "Your opponent is " << player2.show_name() << " (Health: " << player2.show_health() << " Power: " << player2.show_power() << ")\n";

		string user_move, cpu_move;
		bool exit = false;
		while (!exit)
		{

			srand(time(NULL));

			// generate number for cpu turn
			int cpu_turn = (rand() % 5 + 1);

			// if the cpu guarded, apply the guard now
			if (cpu_turn == 5)
				player2.guard();

			// if cpu chose wizard spell, check if it has enough power. if not, do jab instead
			if (cpu_turn == 6)
				if (!player2.show_power() >= 45)
					cpu_turn = 1;

			if (player1.show_power() >= 0) {
				cout << player1.show_name() << " (Health: " << player1.show_health() << ", Power: " << player1.show_power() << ")\n";
				cout << player2.show_name() << " (Health: " << player2.show_health() << ", Power: " << player2.show_power() << ")\n";
				cout << "Your turn:\n";
				cout << "1 - jab (power -10\n";
				cout << "2 - cross (power -20)\n";
				cout << "3 - hook (power -20)\n";
				cout << "4 - uppercut (power -40)\n";
				cout << "5 - guard\n";
				cout << "6 - wizard spell\n";
				cout << "Enter your selection: ";

				// do user turn
				bool legal_input = false;
				
				while (!legal_input)
				{
					cin >> num_input;

					legal_input = true;

					if (num_input < 1 || num_input > 6)
					{
						legal_input = false;

						cout << "Not a valid action. Please enter a number between 1 and 6.\n";
						cout << "Enter your selection: ";
					}
					else if (num_input == 6)
					{
						if (!(player1.show_power() >= 45))
						{
							legal_input = false;

							cout << "You need at least 45 power to use wizard spell.\n";
							cout << "Enter your selection: ";
						}
					}
				}

				switch (num_input)
				{
				case 1:
					user_move = "jab";
					player1.jab(player2);
					break;
				case 2:
					user_move = "cross";
					player1.cross(player2);
					break;
				case 3:
					user_move = "hook";
					player1.hook(player2);
					break;
				case 4:
					user_move = "uppercut";
					player1.uppercut(player2);
					break;
				case 5:
					user_move = "guard";
					player1.guard();
					break;
				case 6:
					user_move = "wizard spell";
					player1.wizard_spell(player2);
					break;
				default:
					cout << "unrecognized input";
					return 1;
				}
			}
			else {
				cout << "Count!! (you are skipped this turn)\n";
				player1.set_power(player1.show_power() + 20);
				user_move = "skip";
			}

			if (player2.show_power() >= 0)
			{
				// do the cpu turn
				switch (cpu_turn) {
				case 1:
					cpu_move = "jab";
					player2.jab(player1);
					break;
				case 2:
					cpu_move = "cross";
					player2.cross(player1);
					break;
				case 3:
					cpu_move = "hook";
					player2.hook(player1);
					break;
				case 4:
					cpu_move = "uppercut";
					player2.uppercut(player1);
					break;
				case 5:
					cpu_move = "guard";
					// cpu already guarded
					break;
				case 6:
					cpu_move = "wizard spell";
					player2.wizard_spell(player1);
				default:
					cout << "unrecognized input";
					return 1;
				}
			}
			else {
				cout << player2.show_name() << "'s turn is skipped\n";
				player2.set_power(player2.show_power() + 20);
				cpu_move = "skip";
			}


			cout << player1.show_name() << " " << user_move << "\n";
			cout << player2.show_name() << " " << cpu_move << "\n";

			player1.set_guard(false);
			player1.normalize_stats();
			player2.set_guard(false);
			player2.normalize_stats();

			if (player1.show_health() <= 0)
			{
				cout << "You have lost!\n";
				return 0;
			}
			if (player2.show_health() <= 0)
			{
				cout << "You have won!\n";
				player2.~player2();
				player1.set_health(player1.show_max_health());
				player1.set_power(player1.show_max_power());
				level++;
				exit = true;
			}

			std::cout << "\n";

		}

	}

	cout << "The game has ended.";

	player1.~player1();

	return 0;
}