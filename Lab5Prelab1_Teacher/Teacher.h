#pragma once

#include "Human.h"

class Teacher : public Human
{
	float knowledge = 100;

public:
	Teacher();
	Teacher(string name);
	Teacher(string name, float knowledge);

	void learn();
	void work();
	float getKnowledge();
	string getName() override;
};
