#include "Teacher.h"

Teacher::Teacher()
{
	name = "Jungsangsri";
	knowledge = 100;
}

Teacher::Teacher(string name)
{
	this->name = name;
	this->knowledge = 100;
}

Teacher::Teacher(string name, float knowledge)
{
	this->name = name;
	this->knowledge = knowledge;
}

void Teacher::learn()
{
	knowledge += 10;
	bank.withdraw(20);
}

void Teacher::work()
{
	bank.deposit(50);
}

float Teacher::getKnowledge()
{
	return knowledge;
}

string Teacher::getName()
{
	return "Prof. " + name;
}