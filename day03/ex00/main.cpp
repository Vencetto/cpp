#include <iostream>
#include "FragTrap.hpp"

int main()
{
	FragTrap godz("Godzilla");
	FragTrap kong("King Kong");
	srand(time(NULL));

	std::cout << RED << "Here are standing " << godz.getName();
	std::cout << " and " << kong.getName() << " in front of each other." << END << std::endl;
	godz.meleeAttack(kong.getName());
	kong.takeDamage((unsigned int)godz.getMeleeAttackDamage());
	kong.rangedAttack(godz.getName());
	godz.takeDamage((unsigned int)kong.getRangedAttackDamage());
	kong.vaulthunter_dot_exe(godz.getName());
	godz.vaulthunter_dot_exe(kong.getName());
	std::cout << RED << "this can't continue forever so..." << END << std::endl;
	return 0;
}