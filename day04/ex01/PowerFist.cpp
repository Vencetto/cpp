//
// Created by Volodymyr ZOMBER.
//

#include "PowerFist.hpp"

/*_____________________Coplien’s form________________________*/

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist() {}

PowerFist::PowerFist(PowerFist const &src) : AWeapon("Power Fist", 8, 50) {
	if (this != &src)
		*this = src;
}

PowerFist& PowerFist::operator=(PowerFist const &src) {
	if (this != &src)
		AWeapon::operator=(src);
	return *this;
}

/*____________________________method_________________________*/

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}