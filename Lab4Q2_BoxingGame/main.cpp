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
			int cpu_turn = (rand() % 4 + 1);

			// if the cpu guarded, apply the guard now
			if (cpu_turn == 5)
				player2.guard();

			if (player1.show_power() >= 0) {
				cout << player1.show_name() << " (Health: " << player1.show_health() << ", Power: " << player1.show_power() << ")\n";
				cout << player2.show_name() << " (Health: " << player2.show_health() << ", Power: " << player2.show_power() << ")\n";
				cout << "Your turn:\n";
				cout << "1 - jab (power -10\n";
				cout << "2 - cross (power -20)\n";
				cout << "3 - hook (power -20)\n";
				cout << "4 - uppercut (power -40)\n";
				cout << "5 - guard\n";
				cout << "Enter your selection: ";

				// do user turn
				cin >> num_input;
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