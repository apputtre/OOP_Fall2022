#pragma once
#include <string>

using std::string;

class Human
{
protected:
	string name;
	int health;

public:

	Human();
	Human(string in_name);
	Human(string in_name, int in_health);

	string show_name();
	int show_health();
	void sleep(int hours);
	void eat(int meals);
	

	~Human();
};