#include <iostream>
#include "Soldier.h"

using std::cout;
using std::cin;

Soldier::Soldier() : Human() {
	power = 100;
}

Soldier::Soldier(string in_name) : Human(in_name) {
	power = 100;
}

Soldier::Soldier(string in_name, int in_health) : Human(in_name, in_health) {

}

Soldier::Soldier(string in_name, int in_health, int in_power) : Human(in_name, in_health) {
	power = in_power;
}

string Soldier::show_name() {
	return "Cap. " + name;
}

int Soldier::show_power() {
	return power;
}

void Soldier::train(int hours) {
	std::cout << show_name() << " trains for " << hours << " hours.";

	health += 10 * hours;
	power += 10 * hours;
}

void Soldier::fight(int hours) {
	std::cout << show_name() << " has fought for " << hours << " hours.";

	health -= 20 * hours;
	power -= 25 * hours;
}