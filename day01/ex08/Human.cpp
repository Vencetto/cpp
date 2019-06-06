/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:49:38 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/15 16:49:39 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {}

Human::Human(std::string name) {
	this->name = name;
}

Human::~Human() {}

void Human::meleeAttack(std::string const & target){
	std::cout << this->name + " melee attacks " << target << std::endl;
}

void Human::rangedAttack(std::string const & target){
	std::cout << this->name + " ranged attacks " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target){
	std::cout << this->name + " intimidating shouts " << target << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target) {

	std::string actionNames[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	typedef void (Human::*Actions)(std::string const & target);
	Actions actions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

	for (int i = 0; i < 3; i++) {
		if (actionNames[i] == action_name) {
			(this->*(actions[i]))(target);
			break;
		}
	}
}
