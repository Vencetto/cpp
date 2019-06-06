/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:54:02 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/17 18:54:03 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
	std::cout << GREEN << "ClapTrap was created." << END << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name) {
	std::cout << GREEN << "ClapTrap " + name + " was created." << END << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap was deleted." << END << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src) {

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

void	ClapTrap::rangedAttack(std::string const & target) {
	std::cout << "ClapTrap " + this->name + " attacks " + target + " at range, causing ";
	std::cout << this->rangedAttackDamage << " points of damage !" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target) {
	std::cout << "ClapTrap " + this->name + " attacks " + target + " melee, causing ";
	std::cout << this->meleeAttackDamage << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int tmp = amount - this->armorDamageReduction;
	if (!tmp)
		tmp = 0;
	this->hitPoints -= tmp;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " + this->name + " attacked, causing " << tmp;
	std::cout << " points of damage !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " + this->name + " was repaired!";
	this->energyPoints += amount;
	this->hitPoints += amount;
	if (this->energyPoints > 100)
		this->energyPoints = this->maxEnergyPoints;
	if (this->hitPoints > 100)
		this->hitPoints = this->maxHitPoints;
	std::cout << " Now he has " << this->hitPoints << " Hit Points "<< std::endl;
	std::cout << "and " << this->energyPoints << " Energy."<< std::endl;
}

/********************************************/
/*				get-methods					*/
/********************************************/

int		ClapTrap::getArmorDamageReduction() const {
	return this->armorDamageReduction;
}

int		ClapTrap::getHitPoints() const {
	return this->hitPoints;
}

int		ClapTrap::getMaxHitPoints() const {
	return this->maxHitPoints;
};

int		ClapTrap::getEnergyPoints() const {
	return this->energyPoints;
}

int		ClapTrap::getMaxEnergyPoints() const {
	return this->maxEnergyPoints;
}

int		ClapTrap::getLevel() const {
	return this->level;
}

std::string	ClapTrap::getName() const {
	return this->name;
}

int		ClapTrap::getMeleeAttackDamage() const {
	return this->meleeAttackDamage;
}

int		ClapTrap::getRangedAttackDamage() const {
	return this->rangedAttackDamage;
}
