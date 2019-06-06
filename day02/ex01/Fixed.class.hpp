/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:26:07 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/12 19:26:08 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

public:

				Fixed();
	explicit	Fixed( const int n );
	explicit	Fixed( const float n );
				Fixed( const Fixed & src);
				~Fixed();

	Fixed &		operator=(Fixed const &rhs);
	float		toFloat() const;
	int			toInt() const;
	int			getRawBits() const;
	void		setRawBits( int const raw );

private:

	int					_value;
	static const int	_bits;
};

std::ostream & operator<<( std::ostream & oou, Fixed const &rhs );

#endif
