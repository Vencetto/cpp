/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:39:17 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/10 19:39:19 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain(void)
{
	return ;
}

Brain::~Brain(void)
{
	return ;
}

std::string Brain::identify(void) const
{
	std::stringstream str;

	str << this;
	return (str.str());
}
