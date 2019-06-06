/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:48:00 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/17 20:48:00 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() {

	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->name = "Casual";
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
	std::cout << "NinjaTrap was created and that means that you are already dead" << std::endl ;
}

NinjaTrap::NinjaTrap(std::string name) {

	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->name = name;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
	std::cout << "NinjaTrap " + this->name + " was created and that means that you are already dead" << std::endl ;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "NinjaTrap just disappear" << std::endl ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src){
	std::cout << "All shurikens copied from " + src.name + " to new one"<< std::endl;
	*this = src;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs) {

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

void		NinjaTrap::ninjaShoebox(ClapTrap &enem) {
	std::cout << this->name + " attacks " << enem.getName();
	std::cout << " with super-ninja style " << std::endl;
	enem.takeDamage(50);
}

void		NinjaTrap::ninjaShoebox(FragTrap & enem) {
	std::cout << this->name << " threw a crazy cat in ";
	std::cout << enem.getName() << std::endl;
	enem.takeDamage(40);
}

void		NinjaTrap::ninjaShoebox(ScavTrap & enem) {
	std::cout << this->name << " threw another ninja in ";
	std::cout << enem.getName() << std::endl;
	enem.takeDamage(1002);
}

void		NinjaTrap::ninjaShoebox(NinjaTrap & enem) {
	std::cout << this->name << " threw shuriken in ";
	std::cout << enem.getName() << std::endl;
	enem.takeDamage(20);
}