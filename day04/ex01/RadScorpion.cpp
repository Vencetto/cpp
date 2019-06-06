//
// Created by Volodymyr ZOMBER
//

#include "RadScorpion.hpp"

/*_____________________Coplien’s form________________________*/

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion"){
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src) {
	if (this != &src)
		*this = src;
}

RadScorpion& RadScorpion::operator=(RadScorpion const &src) {
	if (this != &src)
		Enemy::operator=(src);
	return *this;
}