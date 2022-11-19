#pragma once
#pragma once
#include <string>

using std::string;

class Fighter
{
	// member variables
	string name;
	int health;
	int power;
	int max_health = 150;
	int max_power = 100;
	bool is_guarding = false;

public:
	// default constructor
	Fighter();

	Fighter(string in_name);
	Fighter(string in_name, int in_health);
	Fighter(string in_name, int health, int power);

	// change the fighter's name
	void set_name(string new_name);
	// return the fighter's name
	string show_name();

	// attacks
	void jab(Fighter& opp);
	void cross(Fighter& opp);
	void hook(Fighter& opp);
	void uppercut(Fighter& opp);

	// engage guard (sets 'is_guarding' to true if it is false)
	void guard();
	// explicitly specify the value of guard
	void set_guard(bool new_guard);
	// return value of guard
	bool show_guard();

	// change figher's power
	void set_power(int new_power);
	// return the figher's power
	int show_power();
	// set the fighter's max power
	void set_max_power(int new_max_power);
	// return the fighter's max power
	int show_max_power();

	// change the fighter's health
	void set_health(int new_health);
	// return the fighter's health
	int show_health();
	// change the fighter's max health
	void set_max_health(int new_max_health);
	// return the fighter's health
	int show_max_health();

	/*
		if the fighter's health is greather than max_health then set the fighter's health to max_health
		if the fighter's power is greather than max_power then set the fighter's power to max_power
	*/
	void normalize_stats();

	void drink_potion();
	void splash_poison(Fighter& opp);

	// destructor
	~Fighter();
};

