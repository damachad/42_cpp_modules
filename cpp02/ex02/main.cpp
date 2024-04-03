/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:31:15 by damachad          #+#    #+#             */
/*   Updated: 2024/04/02 15:20:01 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed c(20); 
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;
	
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
	std::cout << "Min (a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << c << " + " << b << " = " << c + b << std::endl;
	std::cout << c << " - " << b << " = " << c - b << std::endl;
	std::cout << c << " / 2.5" << " = " << c / Fixed(2.5f) << std::endl;
	std::cout << "c < b = " << (c < b) << std::endl;
	std::cout << "c >= b = " << (c >= b) << std::endl;
	std::cout << "c == 20 = " << (c == Fixed(20)) << std::endl;
	std::cout << "c != 20 = " << (c != Fixed(20)) << std::endl;
	
	return (0);
}
