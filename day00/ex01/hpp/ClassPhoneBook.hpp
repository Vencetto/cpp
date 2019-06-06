/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:18:51 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/08 17:18:58 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_CLASS_HPP
# define PHONE_BOOK_CLASS_HPP

class phone_book
{
	public:
		phone_book();
		~phone_book();
		void	add();
		void	search();
	private:
		int		count;
		contact	contacts[8];
		void	showName(int i);
		void	showLastName(int i);
		void	showNickname(int i);
		void	showContact(int i);
};

#endif
