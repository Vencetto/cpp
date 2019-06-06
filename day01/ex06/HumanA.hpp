/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:36:37 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/11 17:36:38 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &piu);
		~HumanA();

	Weapon *piu;
	std::string name;
	void attack();
	void setWeapon(Weapon piu);
};

#endif
