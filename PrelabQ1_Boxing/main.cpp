#include <iostream>
#include "Player.h"

using std::count;
using std::cin;
using std::cout;

int main()
{

	Player p1("Bill");
	Player p2("Hans");
	
	cout << "Player 1: " << p1.getName() << " HP " << p1.getHealth() << " POW " << p1.getPower() << "\n";
	cout << "Player 2: " << p2.getName() << " HP " << p2.getHealth() << " POW " << p2.getPower() << "\n\n";

	cout << p1.getName() << " punches " << p2.getName() << "\n";
	p1.punch(p2);

	cout << "Player 1: " << p1.getName() << " HP " << p1.getHealth() << " POW " << p1.getPower() << "\n";
	cout << "Player 2: " << p2.getName() << " HP " << p2.getHealth() << " POW " << p2.getPower() << "\n\n";

	cout << p2.getName() << " punches " << p1.getName() << "\n";
	p2.punch(p1);

	cout << "Player 1: " << p1.getName() << " HP " << p1.getHealth() << " POW " << p1.getPower() << "\n";
	cout << "Player 2: " << p2.getName() << " HP " << p2.getHealth() << " POW " << p2.getPower() << "\n\n";

	cout << p1.getName() << " guards\n";
	p1.guard();
	cout << "Player 1: " << p1.getName() << " HP " << p1.getHealth() << " POW " << p1.getPower() << "\n";
	cout << "Player 2: " << p2.getName() << " HP " << p2.getHealth() << " POW " << p2.getPower() << "\n\n";

	return 0;
}