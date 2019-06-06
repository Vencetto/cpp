/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:30:56 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/17 15:30:57 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/********************************************/
/*				Coplien’s form				*/
/********************************************/

ScavTrap::ScavTrap() :
	hitPoints(100),
	maxHitPoints(100),
	energyPoints(50),
	maxEnergyPoints(50),
	level(1),
	name("Casual"),
	meleeAttackDamage(20),
	rangedAttackDamage(15),
	armorDamageReduction(3) {
	std::cout << "ScavTrap " + name + " was created and IT'S ALIVE!!!!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " + name + " is dead from now." << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
		hitPoints(100),
		maxHitPoints(100),
		energyPoints(50),
		maxEnergyPoints(50),
		level(1),
		name(name),
		meleeAttackDamage(20),
		rangedAttackDamage(15),
		armorDamageReduction(3) {
	std::cout << "ScavTrap " + name + " was created and IT'S ALIVE!!!!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	*this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {

	std::cout << "From now " + this->name + " and " + src.name + " are equal" << std::endl;

	if (this != &src)
	{
		this->hitPoints				= src.hitPoints;
		this->maxHitPoints			= src.maxHitPoints;
		this->energyPoints			= src.energyPoints;
		this->maxEnergyPoints		= src.maxEnergyPoints;
		this->level					= src.level;
		this->name					= src.name;
		this->meleeAttackDamage		= src.meleeAttackDamage;
		this->rangedAttackDamage	= src.rangedAttackDamage;
		this->armorDamageReduction	= src.armorDamageReduction;
	}
	return *this;
}

/********************************************/
/*_______________attacks____________________*/
/********************************************/

void	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "ScavTrap " + this->name + " attacks " + target + " at range, causing ";
	std::cout << this->rangedAttackDamage << " points of damage !" << std::endl;
	std::cout << "\t - You better watch out, cause I am dangerous!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "ScavTrap " + this->name + " attacks " + target + " melee, causing ";
	std::cout << this->meleeAttackDamage << " points of damage !" << std::endl;
	std::cout << "\t - I'll kill you!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	int tmp = amount - this->armorDamageReduction;
	if (!tmp)
		tmp = 0;
	this->hitPoints -= tmp;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ScavTrap " + this->name + " attacked, causing " << tmp;
	std::cout << " points of damage !" << std::endl;
	std::cout << "\t - No! Another hole!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "ScavTrap " + this->name + " was repaired!";
	this->energyPoints += amount;
	this->hitPoints += amount;
	if (this->energyPoints > 100)
		this->energyPoints = this->maxEnergyPoints;
	if (this->hitPoints > 100)
		this->hitPoints = this->maxHitPoints;
	std::cout << " Now he has " << this->hitPoints << " Hit Points "<< std::endl;
	std::cout << "and " << this->energyPoints << " Energy."<< std::endl;
	std::cout << "\t - Yammie! " << std::endl;
}

void	ScavTrap::challengeNewcomer(const std::string & str)
{
	std::string challenges[7] =
	{
		"commit suicide",
		"find his father",
		"become a legend",
		"kill the queen",
		"eat a whole cake and do not be killed by party members",
		"fart in a library",
		"make a flip"
	};
	std::cout << this->name + " accepted challenge to ";
	if (str.empty())
		std::cout << challenges[(rand() % 100) % 7];
	else
		std::cout << str;
	std::cout << " and going to do that" << std::endl;
}