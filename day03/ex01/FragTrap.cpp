/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:52:09 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/13 18:52:10 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <ctime>

/* Constructors and destructor */

FragTrap::FragTrap() :
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(100),
		_maxEnergyPoints(100),
		_level(1),
		_name("Casual"),
		_meleeAttackDamage(30),
		_rangedAttackDamage(20),
		_armorDamageReduction(5)
{
	std::cout << "I was created and I am Casual" << std::endl ;
}

FragTrap::FragTrap(std::string name) :
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(100),
		_maxEnergyPoints(100),
		_level(1),
		_name(name),
		_meleeAttackDamage(30),
		_rangedAttackDamage(20),
		_armorDamageReduction(5)
{
	std::cout << "I was created so you can call me " + name << std::endl ;
}


FragTrap::FragTrap(FragTrap const & src){
	std::cout << "All FR4G-TP's gears copied from " + src._name + " to new one"<< std::endl;
	*this = src;
}

FragTrap::~FragTrap(){
	std::cout << "FR4G-TP " + this->_name + " died :(" << std::endl ;
}

/* Operator */

FragTrap & FragTrap::operator=(FragTrap const & rhs) {

	std::cout << "From now " + this->_name + " and " + rhs._name + " are equal" << std::endl;

	if (this != &rhs)
	{
		this->_hitPoints				= rhs.getHitPoints();
		this->_maxHitPoints			= rhs.getMaxHitPoints();
		this->_energyPoints			= rhs.getEnergyPoints();
		this->_maxEnergyPoints		= rhs.getMaxEnergyPoints();
		this->_level					= rhs.getLevel();
		this->_name					= rhs.getName();
		this->_meleeAttackDamage		= rhs.getMeleeAttackDamage();
		this->_rangedAttackDamage	= rhs.getRangedAttackDamage();
		this->_armorDamageReduction	= rhs.getArmorDamageReduction();
	}
	return *this;
}

/* Methods */

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " + this->_name + " attacks " + target + " at range, causing ";
	std::cout << this->_rangedAttackDamage << " points of damage !" << std::endl;
	std::cout << "\t - I am a tornado of death and bullets! Hehehehe, mwaa ha ha ha, MWAA HA HA HA!" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " + this->_name + " attacks " + target + " melee, causing ";
	std::cout << this->_meleeAttackDamage << " points of damage !" << std::endl;
	std::cout << "\t - Take that, Badass! Heyyah!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	int tmp  = (amount - this->_armorDamageReduction);
	if (!tmp)
		tmp = 0;
	this->_hitPoints -= tmp;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "FR4G-TP " + this->_name + " attacked, causing " << tmp;
	std::cout << " points of damage !" << std::endl;
	std::cout << "\t - Help! I'm bleeding!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP " + this->_name + " was repaired!";
	this->_energyPoints += amount;
	this->_hitPoints += amount;
	if (this->_energyPoints > 100) {
		this->_energyPoints = this->_maxEnergyPoints;
	}
	if (this->_hitPoints > 100) {
		this->_hitPoints = this->_maxHitPoints;
	}
	std::cout << " Now he has " << this->_hitPoints << " Hit Points "<< std::endl;
	std::cout << "and " << this->_energyPoints << " Energy."<< std::endl;
	std::cout << "\t - Aaah. Much better!" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target) {

	std::string attacks[7] =
		{
			"Bullet in a head",
			"Spit in the face",
			"Arrow in the knee",
			"Dagger in the back",
			"fire",
			"Just a shot",
			"You're ugly, nobody loves you"
		};
	if (this->_energyPoints < 25)
		std::cout << "Not enough energy" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		if (this->_energyPoints < 0)
			this->_energyPoints = 0;
		std::cout << this->_name + " attacked " + target + " with " << attacks[(rand() % 100) % 7]
			<< std::endl;
	}
}
/********************************************/
/*				get-methods					*/
/********************************************/

int		FragTrap::getArmorDamageReduction() const {
	return this->_armorDamageReduction;
}

int		FragTrap::getHitPoints() const {
	return this->_hitPoints;
}

int		FragTrap::getMaxHitPoints() const {
	return this->_maxHitPoints;
};

int		FragTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

int		FragTrap::getMaxEnergyPoints() const {
	return this->_maxEnergyPoints;
}

int		FragTrap::getLevel() const {
	return this->_level;
}

std::string	FragTrap::getName() const {
	return this->_name;
}

int		FragTrap::getMeleeAttackDamage() const {
	return this->_meleeAttackDamage;
}

int		FragTrap::getRangedAttackDamage() const {
	return this->_rangedAttackDamage;
}