#include "Person.h"

Person::Person()
{
	this->name = "DEFAULT_NAME";
	this->title = "DEFAULT_TITLE";
	this->department = "DEFAULT_DEPT";
}

Person::Person(string name)
{
	this->name = name;
	this->title = "DEFAULT_TITLE";
	this->department = "DEFAULT_DEPT";
}

Person::Person(string name, string title)
{
	this->name = name;
	this->title = title;
	this->department = "DEFAULT_DEPT";
}

Person::Person(string name, string title, string department)
{
	this->name = name;
	this->title = title;
	this->department = department;
}
string Person::getName() const
{
	return name;
}

string Person::getTitle() const
{
	return title;
}

string Person::getDepartment() const
{
	return department;
}

void Person::printOut() const
{
	cout << name << ", " << title << ", " << department;
}

bool Person::operator==(const Person& rval)
{
	return (this->getName() == rval.getName() && this->getTitle() == rval.getTitle() && this->getDepartment() == rval.getDepartment());
}