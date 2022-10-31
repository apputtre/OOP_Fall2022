#pragma once
#include "human.h"
class Soldier : public Human
{
    int power;

public:
    // constructors
    Soldier();
    Soldier(string in_name);
    Soldier(string in_name, int in_health);
    Soldier(string in_name, int in_health, int in_power);

    // method
    string show_name();
    int show_power();
    void train(int hours);
    void fight(int hours);

};

