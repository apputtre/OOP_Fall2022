#pragma once

#include "Human.h"

class Warrior : public Human
{;
public:
	Warrior();
	Warrior(string name);

	string getName() override;
};
