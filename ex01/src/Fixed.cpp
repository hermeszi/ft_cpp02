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

Fixed::Fixed	() : _rawBits(0) 
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed	(const Fixed& copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

Fixed::Fixed	(int const intValue)
{
	cout << "Int constructor called" << endl;
	_rawBits = intValue * (1 << _fractionalBits);
}

Fixed::Fixed	(float const floatValue)
{
	cout << "Float constructor called" << endl;
	_rawBits = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed& Fixed::operator= (const Fixed& src)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &src)
	{
		this->_rawBits = src.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
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

std::ostream& operator<< (std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}
