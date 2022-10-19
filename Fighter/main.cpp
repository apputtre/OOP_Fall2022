#include <iostream>
#include <string>

using std::count;
using std::cin;
using std::string;
using std::endl;

class Fighter {
	string name;
	int health, power;

public:
	string showname();
	void setname(string newname);
	int showhealth();
	void sethealth(int val);
	void setpower(int val);
	int showpower();
	void eat_poison(int bottle);
	void punch();
};

string Fighter::showname() {
	return name;
}

void Fighter::setname(string newname)
{
	name = newname;
}

int Fighter::showhealth()
{
	return health;
}

void Fighter::sethealth(int val)
{
	health = val;
}

void Fighter::setpower(int val)
{
	power = val;
}

int Fighter::showpower()
{
	return power;
}

void Fighter::punch()
{
	power -= 30;
}

void Fighter::eat_poison(int bottle)
{
	health -= 30 * bottle;
}

Fighter::Fighter()
{
	name = "Steve";
	health = 10;
}

int main()
{
	Fighter player1;

	player1.setname("Hans");
	std::cout << player1.showname() << endl;
	player1.sethealth(100);
	std::cout << "Player health: " << player1.showhealth() << endl;
}