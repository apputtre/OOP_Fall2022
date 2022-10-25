#pragma once
#include <string>

using std::string;

class Fighter
{
	// attribute (data)
	string name;
	int health;
	int power;

public:
	// contructor (set initial value to each object)
	Fighter();		// when user doesn't give any information - default value
	Fighter(string in_name);
	Fighter(string in_name, int in_health);
	Fighter(string in_name, int health, int power);


	// method (what does a fighter can do)
	void setname(string new_name);
	string show_name();

	void punch(Fighter& opp);
	void guard();

	void setpower(int new_power);
	int showpower();

	int show_health();
	
	void drink_potion();
	void splash_poison(Fighter& opp);

	// destructor
	~Fighter();
};

