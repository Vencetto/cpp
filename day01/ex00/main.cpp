/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:30:38 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/09 15:30:40 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap( void )
{
	Pony *Steeve = new Pony("Steeve", "Heap");

	Steeve->sayHello();
	delete Steeve;
}

void	ponyOnTheStack( void )
{
	Pony	Roger("Roger", "Stack");

	Roger.makeRainbow();
}

int		main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
}
