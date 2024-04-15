/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:21 by damachad          #+#    #+#             */
/*   Updated: 2024/04/15 14:15:29 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << GREEN << "Constructors" << RESET << std::endl;
	Intern someRandomIntern;
	AForm *rrf;
	AForm *invalid;
	
	std::cout << std::endl;
	std::cout << GREEN << "Subject test" << RESET << std::endl;
	std::cout << "Making RobotomyRequestForm with target Bender" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	std::cout << std::endl;
	std::cout << RED << "Invalid form" << RESET << std::endl;
	invalid = someRandomIntern.makeForm("invalid request", "Test");
	std::cout << std::endl;
	std::cout << RED << "Destructors called" << RESET << std::endl;
	delete rrf;

	return (0);
}
