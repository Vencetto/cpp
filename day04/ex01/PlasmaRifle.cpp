
#include "PlasmaRifle.hpp"

/*_____________________Coplien’s form________________________*/

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon("Plasma Rifle", 5, 21) {
	if (this != &src)
		*this = src;
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const &src) {
	if (this != &src)
		AWeapon::operator=(src);
	return *this;
}

/*____________________________method_________________________*/

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}