#include "Player.h"

//constructor
Player::Player() {
	name = "Default";
	health = 100;
	power = 100;
}

Player::Player(string name) {
	this->name = name;
	health = 100;
	power = 100;
}

Player::Player(string name, int health) {
	this->name = name;
	this->health = health;
	power = 100;
}

Player::Player(string name, int health, int power) {
	this->name = name;
	this->health = health;
	this->power = power;
}

// method

void Player::setName(string name) {
	this->name = name;
}

string Player::getName() {
	return name;
}

void Player::setPower(int power) {
	this->power = power;
}

int Player::getPower() {
	return power;
}


void Player::setHealth(int health)
{
	this->health = health;
}

int Player::getHealth() {
	return health;
}

void Player::punch(Player& target) {
	target.health -= 20;
	power -= 20;
}

void Player::guard() {
	power += 20;
}

Player::~Player() {}