/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:33:55 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed	(const Fixed& copy);
	Fixed	(int const intValue);
	Fixed	(float const floatValue);

	static	Fixed& min (Fixed& one, Fixed& two);
	static	const Fixed& min (const Fixed& one, const Fixed& two);
	static	Fixed& max (Fixed& one, Fixed& two);
	static	const Fixed& max (const Fixed& one, const Fixed& two);

	Fixed&	operator= (const Fixed& other);

	bool operator > (const Fixed& other) const;
	bool operator < (const Fixed& other) const;
	bool operator >= (const Fixed& other) const;
	bool operator <= (const Fixed& other) const;
	bool operator == (const Fixed& other) const;
	bool operator != (const Fixed& other) const;

	Fixed operator + (const Fixed& other) const;
	Fixed operator - (const Fixed& other) const;
	Fixed operator * (const Fixed& other) const;
	Fixed operator / (const Fixed& other) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator << (std::ostream&, const Fixed& value);

#endif
