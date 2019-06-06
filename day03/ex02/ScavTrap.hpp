/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:31:01 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/17 15:31:02 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

				ScavTrap();
	explicit	ScavTrap(std::string name);
				ScavTrap(ScavTrap const & src);
				~ScavTrap();
	ScavTrap &	operator=(ScavTrap const & src);
	void		challengeNewcomer(const std::string & str);
};


#endif