/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:57:55 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/08 17:57:56 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class contact
{
	public:
		contact();
		~contact();
		std::string	f_name;
		std::string	l_name;
		std::string	nickname;
		std::string	login;
		std::string	postal;
		std::string	email;
		std::string	phone;
		std::string	birth;
		std::string	meal;
		std::string	under_color;
		std::string	dark_secret;
};

#endif
