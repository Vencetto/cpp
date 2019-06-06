/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:20:33 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/08 17:20:33 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

phone_book::phone_book( void )
{
	this->count = 0;
	return ;
}

phone_book::~phone_book( void )
{
	return ;
}

void	phone_book::add( void )
{
	if (this->count < 8)
	{
		std::cout << "Enter first name: " << std::endl;
		std::cin >> this->contacts[this->count].f_name;
		std::cout << "Enter last name: " << std::endl;
		std::cin >> this->contacts[this->count].l_name;
		std::cout << "Enter nickname: " << std::endl;
		std::cin >> this->contacts[this->count].nickname;
		std::cout << "Enter login: " << std::endl;
		std::cin >> this->contacts[this->count].login;
		std::cout << "Enter postal address: " << std::endl;
		std::cin >> this->contacts[this->count].postal;
		std::cout << "Enter email address: " << std::endl;
		std::cin >> this->contacts[this->count].email;
		std::cout << "Enter phone number: " << std::endl;
		std::cin >> this->contacts[this->count].phone;
		std::cout << "Enter birthdate date: " << std::endl;
		std::cin >> this->contacts[this->count].birth;
		std::cout << "Enter favorite meal: " << std::endl;
		std::cin >> this->contacts[this->count].meal;
		std::cout << "Enter underwear color: " << std::endl;
		std::cin >> this->contacts[this->count].under_color;
		std::cout << "Enter darkest secret: " << std::endl;
		std::cin >> this->contacts[this->count].dark_secret;
		this->count++;
	}
	else
		std::cout << "too much contacts" << std::endl;
}

void	phone_book::search( void )
{
	int	i;

	if (this->count == 0) {
		std::cout << "we do not have contacts yet." << std::endl;
		return ;
	}
	i = -1;
	while (++i < this->count)
	{
		std::cout << std::setw(10) << i << '|';
		showName(i);
		showLastName(i);
		showNickname(i);
		std::cout << std::endl;
	}
	std::cout << "which contact want you to see?(enter index): " << std::endl;
	std::cin >> i;
	while (i < 0 || i > 7 || i >= this->count || !std::cin.good())
	{
		if (i == 42)
			return ;
		if (i > this->count)
			std::cout << "we don't have this contact" << std::endl;
		std::cout << "wrong index, try again (42 to exit): " << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> i;
	}
	showContact(i);
}

void	phone_book::showContact(int i)
{
	std::cout << std::setw(17) << "First name: " << this->contacts[i].f_name << std::endl;
	std::cout << std::setw(17) << "Last name: " << this->contacts[i].l_name << std::endl;
	std::cout << std::setw(17) << "Nickname: " << this->contacts[i].nickname << std::endl;
	std::cout << std::setw(17) << "Login: " << this->contacts[i].login << std::endl;
	std::cout << std::setw(17) << "Postal address: " << this->contacts[i].postal << std::endl;
	std::cout << std::setw(17) << "Email address: " << this->contacts[i].email << std::endl;
	std::cout << std::setw(17) << "Phone number: " << this->contacts[i].phone << std::endl;
	std::cout << std::setw(17) << "Birthdate date: " << this->contacts[i].birth << std::endl;
	std::cout << std::setw(17) << "Favorite meal: " << this->contacts[i].meal<< std::endl;
	std::cout << std::setw(17) << "Underwear color: " << this->contacts[i].under_color << std::endl;
	std::cout << std::setw(17) << "Darkest secret: " << this->contacts[i].dark_secret << std::endl;
}

void	phone_book::showName(int i)
{
	if (this->contacts[i].f_name.size() <= 10)
		std::cout << std::setw(10) << this->contacts[i].f_name;
	else
	{
		for (int j = 0; j < 9; j++)
			std::cout << this->contacts[i].f_name[j];
		std::cout << '.';
	}
	std::cout << '|';
}

void	phone_book::showLastName(int i)
{
	if (this->contacts[i].l_name.size() <= 10)
		std::cout << std::setw(10) << this->contacts[i].l_name;
	else
	{
		for (int j = 0; j < 9; j++)
			std::cout << this->contacts[i].l_name[j];
		std::cout << '.';
	}
	std::cout << '|';
}

void	phone_book::showNickname(int i)
{
	if (this->contacts[i].nickname.size() <= 10)
		std::cout << std::setw(10) << this->contacts[i].nickname;
	else
	{
		for (int j = 0; j < 9; j++)
			std::cout << this->contacts[i].nickname[j];
		std::cout << '.';
	}
}
