/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:18:53 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 17:18:55 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int		main(void)
{
	srand (time(NULL));
	ZombieEvent *ze = new ZombieEvent();
	std::cout << "Let's create a zombie" << std::endl;
	Zombie *zomb1 = ze->randomChump();

	std::cout << "Now, for example, we'll create another one" << std::endl;
	Zombie *zomb2 = ze->randomChump();
	std::cout << "Now we have " + zomb1->name + ' ' + zomb1->type + " and " + zomb2->name + ' ' + zomb2->type << std::endl;

	std::cout << "Let's change type to SpiderMan" << std::endl;
	ze->setZombieType("SpiderMan");
	Zombie *zomb3 = ze->newZombie("Friend");

	std::cout << "And now we have " + zomb1->name + ' ' + zomb1->type + " and " +
		zomb2->name + ' ' + zomb2->type + " and "+ zomb3->name + ' ' + zomb3->type << std::endl;
	delete (zomb1);
	delete (zomb2);
	delete (zomb3);
	return (0);
}