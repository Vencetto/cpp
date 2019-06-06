//
// Created by Volodymyr ZOMBER
//

#include "Character.hpp"

/*_____________________Coplien’s form________________________*/

Character::Character() : _name("Casual"), _numberAp(40), _weapon(NULL) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

Character::~Character() {
	std::cout << "Aaargh ..." << std::endl;
}

Character::Character(Character const &src) {
	if (this != &src)
		*this = src;
}

Character& Character::operator=(Character const &src) {
	if (this != &src)
		;
	return *this;
}

/*_______________________methods_____________________________*/

Character::Character(std::string const &name) : _name(name), _numberAp(40), _weapon(NULL) {}

void Character::attack(Enemy *enemy) {
	if (this->_numberAp - this->_weapon->getAPCost() && this->_weapon) {
		this->_numberAp -= this->_weapon->getAPCost();
		std::cout << this->_name + " attacks " + enemy->getType()
					 + " with a " + this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		enemy->takeDamage(_weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

void Character::recoverAP() {
	if (this->_numberAp <= 30)
		this->_numberAp += 10;
}

void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

std::string Character::getName() const {
	return _name;
}

AWeapon *Character::getWeapon() const {
	return this->_weapon;
}
int Character::getAp() const {
	return this->_numberAp;
}

/*___________________operator overload_______________________*/

std::ostream &operator<<(std::ostream &o, const Character &src) {
	o << src.getName() + " has " << src.getAp() << " AP and ";
	if (src.getWeapon())
		o << " wields a " << src.getWeapon()->getName() << std::endl;
	else
		o << " is unarmed" << std::endl;
	return o;
}
