/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:18:26 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 17:18:28 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
		public:
			Zombie(void);
			~Zombie(void);
	void	announce(void);
	void	getName(void);
	void	getType(void);
			std::string	type;
			std::string	name;
};

#endif