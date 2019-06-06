#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		FragTrap ft("Frogy");
		ScavTrap st("Scavy");
		srand(time(NULL));

		ft.vaulthunter_dot_exe(st.getName());
		st.takeDamage((unsigned int) ft.getMeleeAttackDamage());
		st.challengeNewcomer("");
		st.challengeNewcomer("make Satan your friend");
		ft.beRepaired(30);
	}
	std::cout << std::endl << "And it still works" << std::endl << std::endl;
	{
		FragTrap godz("Godzilla");
		FragTrap kong("King Kong");
		srand(time(NULL));

		std::cout << BLUE << "Here are standing " << godz.getName();
		std::cout << " and " << kong.getName() << " in front of each other." << END << std::endl;
		godz.meleeAttack(kong.getName());
		kong.takeDamage((unsigned int)godz.getMeleeAttackDamage());
		kong.rangedAttack(godz.getName());
		godz.takeDamage((unsigned int)kong.getRangedAttackDamage());
		kong.vaulthunter_dot_exe(godz.getName());
		godz.vaulthunter_dot_exe(kong.getName());
		std::cout << BLUE << "this can't continue forever so..." << END << std::endl;
	}
	std::cout << std::endl;
	{
		FragTrap test("just guy");
		ClapTrap stepan(test);

		std::cout << CYAN << "Stepan now have " << stepan.getMaxEnergyPoints() << " Energy" << END << std::endl;
	}
	return 0;
}