/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:30:56 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 15:30:58 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string place)
{
	this->name = name;
	std::cout << "I am born (" << this->name << ") on " << place << std::endl;
}

Pony::~Pony( void )
{
	std::cout << "I am dead now (" << this->name << ")" << std::endl;
}

void	Pony::sayHello( void )
{
	std::cout << "Hello there, my name is " << this->name << std::endl;
}

void	Pony::makeRainbow( void )
{
	std::cout << this->name << "'s rainbow" << std::endl;
	std::cout << " \\ \\ \\" << std::endl;
	std::cout << "  \\ \\ \\" << std::endl;
	std::cout << "   \\ \\ \\" << std::endl;
	std::cout << "    \\ \\ \\" << std::endl;
	std::cout << "     \\ \\ \\" << std::endl;
	std::cout << "      \\ \\ \\" << std::endl;
	std::cout << "       \\ \\ \\" << std::endl;
}