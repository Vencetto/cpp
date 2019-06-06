/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:18:35 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 17:18:39 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void )
{
	return ;
}

ZombieEvent::~ZombieEvent( void )
{
	return ;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *zomb = new Zombie(this->type, name);
	return (zomb);
}

Zombie* ZombieEvent::randomChump( void )
{
	std::string names[6] = {"Terry", "John", "Bloody", "SpongeBob", "Steeve", "Marcus"};
	std::string types[6] = {"Killer", "BrainEater", "SquarePants", "SoulEater", "Marshmallow", "Potato"};

	Zombie *zomb = new Zombie(types[rand() % 6], names[rand() % 6]);
	zomb->announce();
	return (zomb);
}