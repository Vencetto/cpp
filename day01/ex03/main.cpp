/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:18:53 by vzomber           #+#    #+#             */
/*   Updated: 2019/04/02 17:50:12 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int		main(void)
{
	int n;

	srand(time(NULL));
	std::cout << "How many zombies do you want?" << std::endl;
	std::cin >> n;
	if (n < 100)
	{
		ZombieHorde Z(n);
		std::cout << "Just waiting for you to give some input to kill every damn zombie HUAHAHAHAHHAHA" << std::endl;
		std::cin >> n;
	}
	else
		std::cout << "No, that's too much" << std::endl;
	return (0);
}
