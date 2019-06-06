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
# include <cstdlib>
# include <iostream>
# include <ctime>

class Zombie
{
		public:
			Zombie(std::string type, std::string name);
			~Zombie(void);
	void	announce(void);
			std::string	type;
			std::string	name;
};

#endif