/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:36:54 by damachad          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:16 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class D: public Base{};

int	main(void)
{
	D test;
	Base *base;
	
	base = Base::generate();
	std::cout << std::endl;
	std::cout << GREEN << "Type (identify with ptr): " << RESET;
	Base::identify(base);
	std::cout << std::endl;
	std::cout << GREEN << "Type (identify with ref): " << RESET;
	Base::identify(*base);
	std::cout << std::endl;
	std::cout << RED << "Identify NULL Test" << RESET << std::endl;
	Base::identify(NULL);
	std::cout << std::endl;
	std::cout << RED << "Identify unkown ref Test" << RESET << std::endl;
	Base::identify(test);
	std::cout << std::endl;
	std::cout << RED << "Identify unkown ptr Test" << RESET << std::endl;
	Base::identify(&test);
	std::cout << std::endl;
	
	std::cout << RED << "Destructors called" << RESET << std::endl;
	delete base;
	
	return (0);
}
