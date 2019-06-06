/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:26:03 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/16 21:00:22 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <cmath>

const int Fixed::_bits = 8;

/********************************************/
/*				constructors				*/
/********************************************/

Fixed::Fixed() : _value( 0 ) {}

Fixed::Fixed( Fixed const & src ) : _value( 0 ) {
	*this = src;
}

Fixed::Fixed(int const value) {
	this->_value = value << _bits;
}

Fixed::Fixed( const float value ) {
	setRawBits(roundf(value * (1 << _bits)));
}
/*				Destructor					*/

Fixed::~Fixed() {}

/********************************************/
/*				member functions			*/
/********************************************/

float Fixed::toFloat() const {
	return ((float)this->getRawBits() / (1 << _bits));
}

int Fixed::toInt() const {
	return (this->_value >> _bits);
}

int Fixed::getRawBits() const {
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

/********************************************/
/*			comparison operators			*/
/********************************************/

Fixed &	Fixed::operator=(Fixed const & rhs) {
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<(Fixed const &src) const {
	return (this->_value < src.getRawBits());
}

bool	Fixed::operator>(Fixed const &src) const {
	return (this->_value > src.getRawBits());
}

bool	Fixed::operator>=(Fixed const &src) const {
	return (this->_value >= src.getRawBits());
}

bool	Fixed::operator<=(Fixed const &src) const {
	return (this->_value <= src.getRawBits());
}

bool	Fixed::operator!=(Fixed const &src) const {
	return (this->_value != src.getRawBits());
}

bool	Fixed::operator==(Fixed const &src) const {
	return (this->_value == src.getRawBits());
}

std::ostream & operator<<(std::ostream &out, Fixed const & rhs) {
	out << rhs.toFloat();
	return out;
}

/********************************************/
/*			arithmetic operators			*/
/********************************************/

Fixed Fixed::operator+(Fixed const &src) const {
	Fixed tmp;

	tmp._value += src.getRawBits();
	return (tmp);
}

Fixed Fixed::operator-(Fixed const &src) const {
	Fixed tmp;

	tmp._value -= src.getRawBits();
	return (tmp);
}

Fixed Fixed::operator*(Fixed const &src) const {
	Fixed tmp;

	tmp._value = (this->_value * src.getRawBits()) >> _bits;
	return (tmp);
}

Fixed Fixed::operator/(Fixed const &src) const {
	Fixed tmp;

	tmp._value = (this->_value / src.getRawBits()) >> _bits;
	return (tmp);
}

/********************************************/
/*				(++i) & (i++)				*/
/********************************************/

Fixed &		Fixed::operator++() {
	this->_value++;
	return *this;
}

const Fixed		Fixed::operator++( int ) {
	Fixed	tmp(*this);

	++(*this);
	return tmp;
}

Fixed &		Fixed::operator--() {
	this->_value++;
	return *this;
}

const Fixed		Fixed::operator--( int ) {
	Fixed tmp(*this);

	--(*this);
	return tmp;
}

/********************************************/
/*			non member functions			*/
/********************************************/

Fixed Fixed::max(Fixed  &src1, Fixed  &src2) {
	return (src1 > src2) ? src1 : src2;
}

Fixed Fixed::min(Fixed  &src1, Fixed  &src2) {
	return (src1 < src2) ? src1 : src2;
}

const Fixed& Fixed::max(Fixed const &src1, Fixed const &src2) {
	return (src1 > src2) ? src1 : src2;
}

const Fixed& Fixed::min(Fixed const &src1, Fixed const &src2) {
	return (src1 < src2) ? src1 : src2;
}


