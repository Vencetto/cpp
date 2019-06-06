#include "NinjaTrap.hpp"

int main()
{
	NinjaTrap nj("Jo");
	NinjaTrap nj2("Jack");
	ClapTrap cl("Clint");
	ScavTrap sc("Scott");
	FragTrap fr("Frank");

	nj.ninjaShoebox(cl);
	nj.ninjaShoebox(nj2);
	nj.ninjaShoebox(sc);
	nj.ninjaShoebox(fr);
	return 0;
}