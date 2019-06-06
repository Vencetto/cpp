
#include "Sorcerer.hpp"

/*____________Coplien’s form_____________*/

Sorcerer::Sorcerer() {
	std::cout << " Sorcerer Default Constructor was called" << std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout << this->_name + ", " + this->_title + ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) {
	if (this != &src)
		*this = src;
}

Sorcerer& Sorcerer::operator=(Sorcerer const &src) {
	this->_name = src.getName();
	this->_title = src.getTitle();
	return *this;
}

/*__________________parameter constructor____________________*/

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << this->_name + ", " + this->_title + ", is born!" << std::endl;
}

/*___________________operator overload_______________________*/

std::ostream &operator<<(std::ostream &o, const Sorcerer &src) {
	o << "I am " + src.getName() + ", " + src.getTitle() + ", and I like ponies !" << std::endl;
	return o;
}

/*__________________GET_______________________*/

std::string Sorcerer::getName() const {
	return this->_name;
}

std::string Sorcerer::getTitle() const {
	return this->_title;
}

/*_________________methods______________________*/

void Sorcerer::polymorph(Victim const &src) const {
	src.getPolymorphed();
}