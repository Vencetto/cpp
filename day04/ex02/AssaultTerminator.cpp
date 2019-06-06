//
// Created by Volodymyr ZOMBER
//

#include "AssaultTerminator.hpp"

/*_____________________Coplien’s form________________________*/

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I’ll be back ..." << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) {
	if (this != &src)
		*this = src;
}

AssaultTerminator& AssaultTerminator::operator=(AssaultTerminator const &src) {
	(void)src;
	return *this;
}

/*____________________Methods________________________________*/

ISpaceMarine* AssaultTerminator::clone() const {

	ISpaceMarine *clone = new AssaultTerminator(*this);
	return clone;
}

void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}