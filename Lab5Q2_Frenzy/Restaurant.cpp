#include "Restaurant.h"

Restaurant::Restaurant(string name)
{
	this->name = name;
	this->cash = 50;
	this->num_burger = 0;
	this->num_hotdog = 0;
	this->num_pizza = 0;
}

Restaurant::Restaurant(string name = "default", int cash = 50, int num_burger = 0, int num_hotdog = 0, int num_pizza = 0)
{
	this->name = name;
	this->cash = cash;
	this->num_burger = num_burger;
	this->num_hotdog = num_hotdog;
	this->num_pizza = num_pizza;
}

string Restaurant::getName()
{
	return name;
}

int Restaurant::orderFood()
{
	int selection = 0;
	int amount = 0;
	int price = 0;

	cout << "----------Ordering Food----------" << "\n";
	cout << "You have $" << cash << ".\n";
	cout << "1. Burger ($5/each): You have " << num_burger << "\n";
	cout << "2. Pizza ($3/each): You have " << num_pizza << "\n";
	cout << "3. Hotdog ($7/each): You have " << num_hotdog << "\n";
	cout << "0. Exit\n";
	cout << "Please make your selection: ";

	cin >> selection;
	selection--;

	if (selection == -1)
		return 0;

	cout << "Enter amount: ";

	cin >> amount;

	price = prices[selection] * amount;

	if (price > cash)
	{
		cout << "You don't have enough money!\n";
	}
	else
	{
		cash -= price;

		switch (selection)
		{
		case BURGER:
			num_burger += amount;
			break;
		case PIZZA:
			num_pizza += amount;
			break;
		case HOTDOG:
			num_hotdog += amount;
		}

		return 1;
	}
}

void Restaurant::checkInventory()
{
	cout << " --- Check Inventory --- \n";
	cout << "Burger: " << num_burger << "\n";
	cout << "Pizza: " << num_pizza << "\n";
	cout << "Hotdog: " << num_hotdog << "\n";
}

void Restaurant::sellFood(Customer& c)
{
	cout << "---------- Welcome " << c.getName() << " ----------\n";

	int selection;

	cout << "Select a food for " << c.getName() << "\n";
	cout << "1. Burger ($8/each), " << num_burger << "\n";
	cout << "2. Pizza ($5/each), " << num_pizza << "\n";
	cout << "3. Hotdog ($12/each), " << num_hotdog << "\n";
	cout << "4. Nothing\n";

	cin >> selection;
	selection--;

	switch (selection)
	{
	case BURGER:
		if (num_burger > 0)
		{
			cout << "Serving burger to " << c.getName() << "\n";
			num_burger--;
		}
		else
		{
			cout << "You don't have enough burgers!\n";
			selection = 3;
		}
		break;
	case PIZZA:
		if (num_pizza > 0)
		{
			cout << "Serving pizza to " << c.getName() << "\n";
			num_pizza--;
		}
		else
		{
			cout << "You don't have enough pizzas!\n";
			selection = 3;
		}
		break;
	case HOTDOG:
		if (num_hotdog > 0)
		{
			cout << "Serving hotdog to " << c.getName() << "\n";
			num_hotdog--;
		}
		else
		{
			cout << "You don't have enough hotdogs!\n";
			selection = 3;
		}
		break;
	}

	if (selection == 3)
	{
		cout << c.getName() << " got nothing!\n";
		cash -= 10;

		cout << "You lost $10\n";
	}
	else
	{

		int* inventory[3] = {
			&num_burger,
			&num_pizza,
			&num_hotdog
		};

		float amount_made = c.buyFood(1, (Customer::FOOD_ITEM) selection, inventory);

		cash += amount_made;

		cout << "You made " << amount_made << "\n";
	}

	cout << "You now have " << cash << ".\n";

}

int Restaurant::getCash()
{
	return cash;
}
