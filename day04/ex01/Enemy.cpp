//
// Created by Volodymyr ZOMBER
//

#include "Enemy.hpp"

/*_____________________Coplien’s form________________________*/

Enemy::Enemy() {}

Enemy::~Enemy() {}

Enemy::Enemy(Enemy const &src) {
	if (this != &src)
		*this = src;
}

Enemy& Enemy::operator=(Enemy const &src) {
	this->_hp = src.getHP();
	this->_type = src.getType();
	return *this;
}

/*__________________parameter constructor____________________*/

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{}

/*__________________________methods__________________________*/

std::string Enemy::getType() const {
	return _type;
}

int Enemy::getHP() const {
	return _hp;
}

void Enemy::takeDamage(int damage) {

	if (damage && this->_hp)
		this->_hp -= damage;
}