/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:49:44 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/15 16:49:45 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	Human Bob("Bob"), Carl("Carl"), Andrey("Andrey");

	std::cout << "Bob always starts a fight when he's drunk" << std::endl;
	Bob.action("meleeAttack", Andrey.name);
	std::cout << "But Andrey is also drunk, so he throw a cup into Bob" << std::endl;
	Andrey.action("rangedAttack", Bob.name);
	std::cout << "The last one, Carl, is the drunkest badass, he just screams a lot into mirror" << std::endl;
	Carl.action("intimidatingShout", Carl.name);
	return 0;
}
