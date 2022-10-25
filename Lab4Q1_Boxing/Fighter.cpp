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

Fighter::Fighter(string in_name, int in_health, int in_power) {
	name = in_name;
	health = in_health;
	power = in_power;
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
void Fighter::set_power(int new_power) {
	power = new_power;
}

int Fighter::show_power() {
	return power;
}

void Fighter::jab(Fighter& opp) {
	if (opp.is_guarding) {
		opp.health -= 10;
		opp.power -= 5;
	}
	else {
		opp.health -= 10;
	}

	power -= 10;
}

void Fighter::cross(Fighter& opp) {
	if (opp.is_guarding) {
		opp.health -= 15;
		opp.power -= 15;
	}
	else {
		opp.health -= 20;
	}

	power -= 20;
}

void Fighter::hook(Fighter& opp) {
	if (opp.is_guarding) {
		opp.health -= 20;
		opp.power -= 20;
	}
	else {
		opp.health -= 30;
	}

	power -= 30;
}

void Fighter::uppercut(Fighter& opp) {
	if (opp.is_guarding) {
		opp.health -= 30;
	}
	else {
		opp.health -= 40;
	}

	power -= 40;
}

void Fighter::guard() {
	health += 10;
	power += 30;

	if (health > max_health)
		health = max_health;
	if (power > max_power)
		power = max_power;
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