#include <list>
#include <regex>
#include <iostream>

#include "Person.h"

using std::list;
using std::cin;
using std::cout;

// print all users in the list
void print_list(list<Person>& l);
// add a new user to the list
void add_user(list<Person>& l);
// search for a user in the list
void search_user(list<Person>& l);
// remove a user from the list
void remove_user(list<Person>& l);
// convert a string to lowercase
string string_tolower(string s);

int main()
{
	// define the People instances which will populate the list
	Person p1("House", "MD", "Pathology");
	Person p2("Scully", "Special Agent", "FBI");
	Person p3("Columbo", "Detective", "Criminal Justice");
	Person p4("Angell", "Professor", "Semetic Languages");
	Person p5("Bilgewater", "Lievtenant Colonel", "Army");

	// https://cplusplus.com/reference/list/list/
	list<Person> l;

	// add the users to the list
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);

	bool exit = false;
	while (!exit)
	{
		cout << "Please select one of the following options.\n";
		cout << "1 - Print current list\n";
		cout << "2 - Add a new user to this list\n";
		cout << "3 - Search for a user\n";
		cout << "4 - Remove a person from this list\n";
		cout << "5 - Exit\n";

		int user_input;
		cout << "Selection: ";
		cin >> user_input;

		cout << "\n";

		switch (user_input)
		{
		case 1:
			print_list(l);
			break;
		case 2:
			add_user(l);
			break;
		case 3:
			search_user(l);
			break;
		case 4:
			remove_user(l);
			break;
		case 5:
			exit = true;
			break;
		default:
			cout << "Unrecognized input\n";
			break;
		}
		
		cout << "\n";
	}
	
	return 0;
}

void print_list(list<Person>& l)
{
	for (Person p : l)
	{
		p.printOut();
		cout << "\n";
	}
}

void add_user(list<Person>& l)
{
	string name, title, department;

	// clear the whitespace characters from cin (otherwise this fails to get input)
	std::getline(cin, name);

	cout << "Please enter a name: ";
	std::getline(cin, name);
	cout << "Please enter a title: ";
	std::getline(cin, title);
	cout << "Please enter a department: ";
	std::getline(cin, department);

	// add a new user with the specified values
	l.push_back(Person(name, title, department));
}

void search_user(list<Person>& l)
{
	string user_input;

	// clear the whitespace characters from cin
	getline(cin, user_input);

	cout << "What attribute would you like to search for? (name, title, department): ";
	getline(cin, user_input);
	user_input = string_tolower(user_input);

	// declare the function we're going to use to compare the users
	string(*getfield)(Person p) = nullptr;

	// https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
	// use lambda expressions to define the function
	if (user_input == "name")
		getfield = [](Person p) {return p.getName(); };
	else if (user_input == "title")
		getfield = [](Person p) {return p.getTitle(); };
	else if (user_input == "department")
		getfield = [](Person p) {return p.getDepartment(); };
	else
	{
		cout << user_input << " is not a recognized field.\n";
		return;
	}

	cout << "Please enter which " << user_input << " to search for: ";
	std::getline(cin, user_input);
	user_input = string_tolower(user_input);

	list<Person>::iterator it = l.begin();

	// compare call the lambda expression on each user to compare against the input
	while (it != l.end())
		if (string_tolower(getfield(*it)) == user_input)
			break;
		else
			it++;
	
	if (it == l.end())
		cout << "The user was not found in the list.\n";
	else
	{
		cout << "The specified user was found at position " << (std::distance(l.begin(), it)) << ":\n";
		(*it).printOut();
		cout << "\n";
	}

}

//https://cplusplus.com/reference/list/list/remove_if/
void remove_user(list<Person>& l)
{
	string user_input;

	// clear whitespace
	std::getline(cin, user_input);

	cout << "Whom would you like to remove?: ";
	std::getline(cin, user_input);


	// use a lambda expression to remove all users matching the specified name
	l.remove_if(
		[user_input](Person& p)
		{
			return p.getName() == user_input;
		}
	);

	cout << "Users by the name " << user_input << " have been removed from the system.\n";
}

// https://cplusplus.com/reference/algorithm/transform/?kw=transform
string string_tolower(string s)
{
	std::transform(s.begin(), s.end(), s.begin(), tolower);

	return s;
}
