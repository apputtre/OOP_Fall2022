#include "human.h"

Human::Human()
{
	name = "Default";
	health = 100;
}
Human::Human(string in_name) {
	name = in_name;
	health = 100;
}

Human::Human(string in_name, int in_health) {
	name = in_name;
	health = in_health;
}

string Human::show_name() {
	return name;
}

int Human::show_health() {
	return health;
}

void Human::sleep(int hours) {
	health += 5 * hours;
}

void Human::eat(int meals) {
	health += 3 * meals;
}

Human::~Human() {}