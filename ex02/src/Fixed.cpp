/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <cmath>

using std::endl;
using std::cout;

Fixed& Fixed::min (Fixed& one, Fixed& two)
{
	return ((one < two) ? one : two);
}

const Fixed& Fixed::min (const Fixed& one, const Fixed& two)
{
	return ((one < two) ? one : two);
}

Fixed& Fixed::max (Fixed& one, Fixed& two)
{
	return ((one > two) ? one : two);
}

const Fixed& Fixed::max (const Fixed& one, const Fixed& two)
{
	return ((one > two) ? one : two);
}

Fixed::Fixed	() : _rawBits(0) 
{
	//cout << "Default constructor called" << endl;
}

Fixed::Fixed	(const Fixed& copy)
{
	//cout << "Copy constructor called" << endl;
	*this = copy;
}

Fixed::Fixed	(int const intValue)
{
	//cout << "Int constructor called" << endl;
	_rawBits = intValue * (1 << _fractionalBits);
}

Fixed::Fixed	(float const floatValue)
{
	//cout << "Float constructor called" << endl;
	_rawBits = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed& Fixed::operator = (const Fixed& other)
{
	//cout << "Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_rawBits = other.getRawBits();
	}
	return (*this);
}

bool Fixed::operator > (const Fixed& other) const
{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator < (const Fixed& other) const
{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator >= (const Fixed& other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator <= (const Fixed& other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator == (const Fixed& other) const
{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator != (const Fixed& other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed Fixed::operator + (const Fixed& other) const
{
	Fixed result;

	result.setRawBits(this->_rawBits + other._rawBits);
	return (result);
}

Fixed Fixed::operator - (const Fixed& other) const
{
	Fixed result;

	result.setRawBits(this->_rawBits - other._rawBits);
	return (result);
}

Fixed Fixed::operator * (const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->_rawBits * other._rawBits) >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator / (const Fixed& other) const
{
	Fixed result;

	result.setRawBits((this->_rawBits << _fractionalBits) / other._rawBits);
	return (result);
}

Fixed& Fixed::operator++()
{
	++this->_rawBits;
	return (*this);
}

Fixed& Fixed::operator--()
{
	--this->_rawBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed pre(*this);

	++this->_rawBits;
	return (pre);
}

Fixed Fixed::operator--(int)
{
	Fixed pre(*this);

	--this->_rawBits;
	return (pre);
}

Fixed::~Fixed()
{
	//cout << "Destructor called" << endl;
}

int		Fixed::getRawBits(void) const
{
	//cout << "getRawBits member function called" << endl;
	return (this->_rawBits);	
}

void	Fixed::setRawBits (int const raw)
{	
	//cout << "setRawBits member function called" << endl;
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float> (_rawBits) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_rawBits / (1 << _fractionalBits));
}

std::ostream& operator << (std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}
