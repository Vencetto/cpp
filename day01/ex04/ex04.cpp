/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:04:34 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/10 19:04:34 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << "We have a string -> " + str << std::endl;
	std::cout << "And we have ptr -> " + *ptr << std::endl;
	std::cout << "Also we have ref -> " + ref << std::endl;
	return (0);
}
