/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:34:12 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/08 19:34:15 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	start(void)
{
	std::cout << "********* MY AWESOME PHONEBOOK ********" << std::endl;
	std::cout << "* -> Enter \"ADD\" to add new contact   *" << std::endl;
	std::cout << "* -> Enter \"SEARCH\" to search contact *" << std::endl;
	std::cout << "* -> Enter \"EXIT\" to exit             *" << std::endl;
	std::cout << "***************************************" << std::endl;
}

int		main(void)
{
	phone_book	book;
	std::string	tmp;

	start();
	while (true)
	{
		std::cout << "Please, enter command." << std::endl;
		std::cin >> tmp;
		if (tmp.compare("ADD") == 0)
			book.add();
		else if (tmp.compare("SEARCH") == 0)
			book.search();
		else if (tmp.compare("EXIT") == 0)
			exit(0);
		else
			std::cout << "unknown command" << std::endl;
	}
	return (0);
}
