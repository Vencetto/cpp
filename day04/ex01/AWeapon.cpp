
#include "AWeapon.hpp"

/*______________________Coplien's form_______________________*/

AWeapon::AWeapon() {
	std::cout << "AWeapon Default Constructor was called." << std::endl;
}

AWeapon::~AWeapon() {
	std::cout << "AWeapon Destructor was called." << std::endl;
}

AWeapon::AWeapon(AWeapon const &src) {
	if (this != &src)
		*this = src;
}

AWeapon& AWeapon::operator=(AWeapon const &src) {
	this->_name = src.getName();
	this->_damage = src.getDamage();
	this->_apcost = src.getAPCost();
	return *this;
}

/*____________________Parameter constructor__________________*/

AWeapon::AWeapon(std::string const &name, int apcost, int damage) {
	this->_name = name;
	this->_apcost = apcost;
	this->_damage = damage;
}

/*_________________________getters___________________________*/

std::string AWeapon::getName() const {
	return this->_name;
}

int AWeapon::getDamage() const {
	return this->_damage;
}

int AWeapon::getAPCost() const {
	return this->_apcost;
}