#include <iostream>
#include <string>

#include "Fighter.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
	// start a game
	// create a fighter
	Fighter player1;

	// display data of player1
	cout << "Player 1: " << player1.show_name() << " (health): " << player1.show_health() << endl;

	//// create a second player
	//cout << "Enter a name of second player: ";
	//string username;
	//cin >> username;

	//Fighter player2(username);
	//// display data of player2
	//cout << "Player 2: " << player2.show_name() << " (health): " << player2.show_health() << endl;

	// create third player
	Fighter player3("John", 50);
	// display data of player2
	cout << "Player 3: " << player3.show_name() << " (health): " << player3.show_health() << endl;

	// player 1 punch player 3
	cout << "player3 got punch" << endl;
	player1.punch(player3);
	cout << "Player 3: " << player3.show_name() << " (health): " << player3.show_health() << endl;

	cout << "player 1 got poisoned" << endl;
	player3.splash_poison(player1);
	cout << "Player 1: " << player1.show_name() << " (health): " << player1.show_health() << endl;

	cout << "player 1 drank a potion" << endl;
	player1.drink_potion();
	cout << "Player 1: " << player1.show_name() << " (health): " << player1.show_health() << endl;

	// destructor
	//	player1.~Fighter();

	// display data of player1
	//	cout << player1.show_name() << " (health): " << player1.show_health() << endl;


	return 0;
}