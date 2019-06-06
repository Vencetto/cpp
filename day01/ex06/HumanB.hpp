/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HunamB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:36:42 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/11 17:36:43 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

	Weapon *piu;
	std::string name;
	void attack();
	void setWeapon(Weapon &piu);
};

#endif
