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
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed() : _value( 0 ) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
	this->_value = value << _bits;
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed( const float value ) {
	setRawBits(roundf(value * (1 << _bits)));
	std::cout << "Float Constructor called" << std::endl;
}

float Fixed::toFloat() const {
	return ((float)this->getRawBits() / (1 << _bits));
}

int Fixed::toInt() const {
	return (this->_value >> _bits);
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
	return (*this);
}

int Fixed::getRawBits() const {
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

std::ostream & operator<<( std::ostream &out, Fixed const & rhs) {
	out << rhs.toFloat();
	return out;
}
