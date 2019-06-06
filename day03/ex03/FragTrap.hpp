/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:52:13 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/13 18:52:14 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
					FragTrap();
	explicit		FragTrap(std::string name);
					~FragTrap();
					FragTrap(FragTrap const & src);
	FragTrap &		operator=(FragTrap const & rhs);
	void			vaulthunter_dot_exe(std::string const & target);
};

#endif
