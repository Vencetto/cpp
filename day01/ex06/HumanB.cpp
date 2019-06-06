/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HunamB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:45:07 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/11 17:45:08 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack()
{
	std::cout << this->name + " attacks with his " + piu->type << std::endl;
}

void	HumanB::setWeapon(Weapon &piu)
{
	this->piu = &piu;
}