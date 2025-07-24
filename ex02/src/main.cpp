/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/07/17 17:31:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Fixed.hpp"

 int	main( void )
 {
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));
	Fixed	const c(10);
	Fixed	const d(42.42f);
	Fixed	e = b;

	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is now " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is now " << a << std::endl;

	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e (copy of b) is " << e << std::endl;

	std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;

	std::cout << "Arithmetic:" << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "d - c = " << d - c << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "d / c = " << d / c << std::endl;

	std::cout << "Comparison:" << std::endl;
	std::cout << "Is c > d? " << (c > d) << std::endl;
	std::cout << "Is c < d? " << (c < d) << std::endl;
	std::cout << "Is c == Fixed(10)? " << (c == Fixed(10)) << std::endl;

	return (0);
 }
