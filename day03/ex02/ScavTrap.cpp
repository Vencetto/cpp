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

ScavTrap::ScavTrap() {
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->name = "Casual";
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	std::cout << "ScavTrap " + name + " was created and IT'S ALIVE!!!!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " + name + " is dead from now." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->name = name,
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
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