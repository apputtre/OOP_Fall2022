#include <iostream>
#include <string>
#include "Human.h"
#include "Soldier.h"

using std::cin;
using std::cout;
using std::string;

int main() {
	Human user1("Jim", 70);

	cout << user1.show_name() << " (health): " << user1.show_health() << "\n";

	user1.eat(2);

	cout << user1.show_name() << " (health): " << user1.show_health() << "\n";

	Soldier user2("Bob", 90);

	user2.train(10);

	return 0;
}