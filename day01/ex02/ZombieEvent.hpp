/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:18:45 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 17:18:47 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class ZombieEvent
{
	public:
			ZombieEvent(void);
			~ZombieEvent(void);
	void	setZombieType(std::string type);
	Zombie*	newZombie(std::string name);
	Zombie*	randomChump(void);
	std::string	type;
};

#endif
