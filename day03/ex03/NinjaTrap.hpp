/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:48:05 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/17 20:48:06 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

public:

	NinjaTrap();
	explicit	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap();
	NinjaTrap &	operator=(NinjaTrap const & src);
	void		ninjaShoebox(ClapTrap & enem);
	void		ninjaShoebox(FragTrap & enem);
	void		ninjaShoebox(ScavTrap & enem);
	void		ninjaShoebox(NinjaTrap & enem);

};

#endif
