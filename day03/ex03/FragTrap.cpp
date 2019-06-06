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

/* Constructors and destructor */

FragTrap::FragTrap() {
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->name = "Casual";
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	std::cout << "FragTrap was created and I am Casual" << std::endl ;
}

FragTrap::FragTrap(std::string name) {
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->name = name;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	std::cout << "FragTrap was created so you can call me " + name << std::endl ;
}


FragTrap::FragTrap(FragTrap const & src){
	std::cout << "All FR4G-TP's gears copied from " + src.name + " to new one"<< std::endl;
	*this = src;
}

FragTrap::~FragTrap(){
	std::cout << "FR4G-TP " + this->name + " died :(" << std::endl ;
}

/* Operator */

FragTrap & FragTrap::operator=(FragTrap const & rhs) {

	std::cout << "From now " + this->name + " and " + rhs.name + " are equal" << std::endl;

	if (this != &rhs)
	{
		this->hitPoints				= rhs.getHitPoints();
		this->maxHitPoints			= rhs.getMaxHitPoints();
		this->energyPoints			= rhs.getEnergyPoints();
		this->maxEnergyPoints		= rhs.getMaxEnergyPoints();
		this->level					= rhs.getLevel();
		this->name					= rhs.getName();
		this->meleeAttackDamage		= rhs.getMeleeAttackDamage();
		this->rangedAttackDamage	= rhs.getRangedAttackDamage();
		this->armorDamageReduction	= rhs.getArmorDamageReduction();
	}
	return *this;
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
	if (this->energyPoints < 25)
		std::cout << "Not enough energy" << std::endl;
	else
	{
		this->energyPoints -= 25;
		if (this->energyPoints < 0)
			this->energyPoints = 0;
		std::cout << this->name + " attacked " + target + " with " << attacks[(rand() % 100) % 7]
			<< std::endl;
	}
}
