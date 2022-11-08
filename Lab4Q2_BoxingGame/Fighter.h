#pragma once
#pragma once
#include <string>

using std::string;

class Fighter
{
	// attribute (data)
	string name;
	int health;
	int power;
	int max_health = 150;
	int max_power = 100;
	bool is_guarding = false;

public:
	// contructor (set initial value to each object)
	Fighter();		// when user doesn't give any information - default value
	Fighter(string in_name);
	Fighter(string in_name, int in_health);
	Fighter(string in_name, int health, int power);


	// method (what does a fighter can do)
	void set_name(string new_name);
	string show_name();

	void jab(Fighter& opp);
	void cross(Fighter& opp);
	void hook(Fighter& opp);
	void uppercut(Fighter& opp);

	void guard();
	void set_guard(bool new_guard);
	bool show_guard();

	void set_power(int new_power);
	int show_power();
	void set_max_power(int new_max_power);
	int show_max_power();

	void set_health(int new_health);
	int show_health();
	void set_max_health(int new_max_health);
	int show_max_health();

	void normalize_stats();

	void drink_potion();
	void splash_poison(Fighter& opp);

	// live code
	void wizard_spell(Fighter& opp);

	// destructor
	~Fighter();
};
