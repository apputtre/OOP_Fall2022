#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Person
{
	string name, title, department;

public:
	Person();
	Person(string name);
	Person(string name, string title);
	Person(string name, string title, string derpartment);

	string getName() const;
	string getTitle() const;
	string getDepartment() const;
	void printOut() const;

	bool operator==(const Person& rval);
};
