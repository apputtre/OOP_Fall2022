#include "Warrior.h"

Warrior::Warrior() : Human("Conan") {}

Warrior::Warrior(string name) : Human(name) {}

string Warrior::getName()
{
	return "Warrior " + name;
}
