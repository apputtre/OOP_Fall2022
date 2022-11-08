#pragma once
#pragma once
#include <string>

using std::string;

class Player
{
	string name;
	int health;
	int power;

public:
	Player();
	Player(string name);
	Player(string name, int health);
	Player(string name, int health, int power);


	void setName(string name);
	string getName();

	void setPower(int power);
	int getPower();

	void setHealth(int health);
	int getHealth();

	void punch(Player& target);
	void guard();

	// destructor
	~Player();
};

