#include "Fighter.h"

//constructor
Fighter::Fighter() {
	name = "Tedi";
	health = 99;
}

Fighter::Fighter(string in_name) {
	name = in_name;
	health = 100;
}

Fighter::Fighter(string in_name, int in_health) {
	name = in_name;
	health = in_health;
}

Fighter::Fighter(string in_name, int health, int power) {
	name = in_name;
	health = health;
	power = power;
}

// method

void Fighter::setname(string name) {
	name = name;
}

string Fighter::show_name() {
	return name;
}

int Fighter::show_health() {
	return health;
}
void Fighter::setpower(int new_power) {
	power = new_power;
}

int Fighter::showpower() {
	return power;
}


void Fighter::punch(Fighter& opp) {
	opp.health = opp.health - 10;
}

void Fighter::guard() {
	power += 20;
}

void Fighter::drink_potion()
{
	health += 20;
}

void Fighter::splash_poison(Fighter& opp)
{
	opp.health -= 35;
}

// destructor
Fighter::~Fighter() {

}