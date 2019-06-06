//
// Created by Volodymyr ZOMBER
//

#include "SuperMutant.hpp"

/*_____________________Coplien’s form________________________*/

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant"){
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) {
	if (this != &src)
		*this = src;
}

SuperMutant& SuperMutant::operator=(SuperMutant const &src) {
	if (this != &src)
		Enemy::operator=(src);
	return *this;
}

/*_________________________Overloads_________________________*/

void SuperMutant::takeDamage(int damage) {
	if (damage > 3 && this->_hp)
	{
		this->_hp -= damage - 3;
		std::cout << "Enemy " + this->_type + "takes " << damage << " damage !" << std::endl;
	}
}