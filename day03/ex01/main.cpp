#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap ft("Frogy");
	ScavTrap st("Scavy");
	srand(time(NULL));

	ft.vaulthunter_dot_exe(st.name);
	st.takeDamage((unsigned int)ft.getMeleeAttackDamage());
	st.challengeNewcomer("");
	st.challengeNewcomer("make Satan your friend");
	ft.beRepaired(30);
	return 0;
}