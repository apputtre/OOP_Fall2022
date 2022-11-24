#include <iostream>
#include "Human.h"
#include "Warrior.h"
#include "Teacher.h"

using std::cout;

int main()
{
	Human* tom = new Human("Tom");
	Teacher* alice = new Teacher("Alice");
	Warrior* andy = new Warrior("Andy");
	Teacher* kate = new Teacher("Kate");

	Human* humans[4] = { tom, alice, andy, kate };
	
	for (Human* h : humans)
		cout << h->getName() << "\n";

	return 0;
}