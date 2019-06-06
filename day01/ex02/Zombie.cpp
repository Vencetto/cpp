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

Zombie::Zombie(std::string type, std::string name)
{
	this->type = type;
	this->name = name;
	std::cout << "\tZombie " + this->name + " of type(" + this->type + ") was created." << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "\tZombie " + this->name + " of type(" + this->type + ") was killed." << std::endl;
	return ;
}

void	Zombie::announce( void )
{
	std::cout << "<" + this->name + " (" + type + ")>" + " Braiiiiiiinnnssss..." << std::endl;
}
