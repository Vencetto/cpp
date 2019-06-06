/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:26:03 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/12 19:26:04 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed() : _value( 0 ) {

	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _value( 0 ) {

	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {

	std::cout << "Assignment operator called" << std::endl;

	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {

	o << "The value is : " << rhs.getRawBits();

	return o;
}

const int Fixed::_bits = 8;