
#include "Peon.hpp"

/*_____________________Coplien’s form________________________*/

Peon::Peon() : Victim() {
	std::cout << " Peon Default Constructor was called" << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src) {
	if (this != &src)
		*this = src;
}

Peon& Peon::operator=(Peon const &src) {
	this->_name = src.getName();
	return *this;
}

/*__________________parameter constructor____________________*/

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

/*___________________operator overload_______________________*/

std::ostream &operator<<(std::ostream &o, const Peon &src) {
	o << "I'm " + src.getName() + ", and I like otters !" << std::endl;
	return o;
}

/*___________________methods_______________________*/

void Peon::getPolymorphed() const {
	std::cout << this->_name + " has been turned into a pink pony !" << std::endl;
}