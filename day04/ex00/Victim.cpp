
#include "Victim.hpp"

/*____________Coplien’s form_____________*/

Victim::Victim() {
	std::cout << "Victim Default Constructor was called" << std::endl;
}

Victim::~Victim() {
	std::cout << "Victim " + this->_name + " just died for no apparent reason !" << std::endl;
}

Victim::Victim(Victim const &src) {
	if (this != &src)
		*this = src;
}

Victim& Victim::operator=(Victim const &src) {
	this->_name = src.getName();
	return *this;
}

/*__________________parameter constructor____________________*/

Victim::Victim(std::string name) :_name(name) {
	std::cout << "Some random victim called " + this->_name + " just popped !" << std::endl;
}

/*__________________GET_______________________*/

std::string Victim::getName() const {
	return this->_name;
}

/*___________________operator overload_______________________*/

std::ostream &operator<<(std::ostream &o, const Victim &src) {
	o << "I'm " + src.getName() + ", and I like otters !" << std::endl;
	return o;
}

/*___________________methods_______________________*/

void Victim::getPolymorphed() const {
	std::cout << this->_name + " has been turned into a cute little sheep !" << std::endl;
}