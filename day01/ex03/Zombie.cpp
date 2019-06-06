/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:18:01 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 17:18:08 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	return ;
}

void	Zombie::announce( void )
{
	std::cout << "<" + this->name + " (" + type + ")>" + " Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::getName( void )
{
	std::string names[6] = {"Terry", "John", "Bloody", "SpongeBob", "Steeve", "Marcus"};
	this->name =  names[rand() % 6];
}

void	Zombie::getType( void )
{
	std::string types[6] = {"Killer", "BrainEater", "SquarePants", "SoulEater", "Marshmallow", "Potato"};
	this->type = types[rand() % 6];
}