/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:31:04 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 15:31:05 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>
# include <iostream>

class Pony
{
	public:
		Pony(std::string name, std::string place);
		~Pony();
		std::string	name;
		void	sayHello(void);
		void	makeRainbow(void);
};

#endif
