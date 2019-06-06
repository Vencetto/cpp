/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:45:02 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/11 17:45:03 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &piu)
{
	this->name = name;
	this->piu = &piu;
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->piu->type<< std::endl;
}

void	HumanA::setWeapon(Weapon piu)
{
	this->piu = &piu;
}