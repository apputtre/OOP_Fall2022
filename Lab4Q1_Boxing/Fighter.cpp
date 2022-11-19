#include "Fighter.h"

// default constructor
Fighter::Fighter() {
	name = "Tedi";
	health = 100;
	power = 150;
}

Fighter::Fighter(string in_name) {
	name = in_name;
	health = 100;
	power = 150;
}

Fighter::Fighter(string in_name, int in_health) {
	name = in_name;
	health = in_health;
	power = 150;
}

Fighter::Fighter(string in_name, int in_health, int in_power) {
	name = in_name;
	health = in_health;
	power = in_power;
}

void Fighter::set_name(string new_name) {
	name = new_name;
}

string Fighter::show_name() {
	return name;
}

void Fighter::set_health(int new_health)
{
	health = new_health;
}

int Fighter::show_health() {
	return health;
}

void Fighter::set_max_health(int new_max_health)
{
	max_health = new_max_health;
}

int Fighter::show_max_health()
{
	return max_health;
}

void Fighter::set_power(int new_power) {
	power = new_power;
}

int Fighter::show_power() {
	return power;
}

void Fighter::set_max_power(int new_max_power)
{
	max_power = new_max_power;
}

int Fighter::show_max_power()
{
	return max_power;
}

void Fighter::jab(Fighter& opp) {
	// if the opponent is guarding, then he should lose some power
	if (opp.show_guard()) {
		opp.health -= 10;
		opp.power -= 5;
	}
	// otherwise, he just loses the health
	else {
		opp.health -= 10;
	}

	power -= 10;
}

void Fighter::cross(Fighter& opp) {
	if (opp.show_guard()) {
		opp.health -= 15;
		opp.power -= 15;
	}
	else {
		opp.health -= 20;
	}

	power -= 20;
}

void Fighter::hook(Fighter& opp) {
	if (opp.show_guard()) {
		opp.health -= 20;
		opp.power -= 20;
	}
	else {
		opp.health -= 30;
	}

	power -= 30;
}

void Fighter::uppercut(Fighter& opp) {
	if (opp.show_guard()) {
		opp.health -= 30;
	}
	else {
		opp.health -= 40;
	}

	power -= 40;
}

// if the fighter guards, he should recover some health and power
void Fighter::guard() {
	set_guard(true);

	health += 10;
	power += 30;
}

void Fighter::set_guard(bool new_guard)
{
	is_guarding = new_guard;
}

bool Fighter::show_guard()
{
	return is_guarding;
}

// make sure health isn't above max_health and power isn't above max_power
void Fighter::normalize_stats()
{
	if (show_health() > show_max_health())
		set_health(show_max_health());
	if (show_power() > show_max_power())
		set_power(show_max_power());
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