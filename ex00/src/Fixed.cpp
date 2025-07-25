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

#include "Fixed.hpp"

using std::endl;
using std::cout;

Fixed::Fixed() : _rawBits(0) 
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed	(const Fixed& copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
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
	cout << "getRawBits member function called" << endl;
	return (this->_rawBits);	
}

void	Fixed::setRawBits (int const raw)
{	
	cout << "setRawBits member function called" << endl;
	this->_rawBits = raw;
}
