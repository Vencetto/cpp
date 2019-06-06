/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:51:59 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/10 16:52:00 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	this->ptr = new Zombie[n];
	this->number = n;

	for (int i = 0; i < n; i++)
	{
		this->ptr[i].getName();
		this->ptr[i].getType();
		this->ptr[i].announce();
	}
}

ZombieHorde::~ZombieHorde( void )
{
	for (int i = 0; i < this->number; i++)
	{
		std::cout << '<' + this->ptr[i].name + " (" + this->ptr[i].type + ")> has died." << std::endl;
	}
}
