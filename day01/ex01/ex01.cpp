/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:09:59 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/15 14:55:00 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void memoryLeak()
{
	std::string	*panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}
